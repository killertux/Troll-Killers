#include "Server.hpp"

Server::Server(){
	char buffer[255];
	config.config_load("server.cfg");
	config.config_get(buffer,"Port");
	port=strtol(buffer,NULL,0);
	config.config_get(buffer,"Users");
	users=strtol(buffer,NULL,0);
	config.config_get(buffer,"Map");
	
	std::cout << buffer <<std::endl;
	
	std::cout << "Creating the server...\n";
	conn.create_server(port,users);
	std::cout << "Server created! \nListening to the port " << port << std::endl;
	players = new SCharacter*[users];
	for(int i=0;i<users;i++)
		players[i]=NULL;
	
	if(!map.load_map(buffer)){
		std::cout << "Error loading the map\n";
		exit(0);
	}
	map.calculateSpawn();
	blueTeamN=0;
	redTeamN=0;
}

Server::~Server(){
	delete writeThread;
	delete [] players;
}

void Server::main_loop(){
	_msg msgTmp;
	_data senderBuffer;
	bool done=false;
	writeThread=new boost::thread(&Server::user_handle,this);
	while(!done){
		dataMu.lock();
		while(conn.event_service(1/FPS)>0){
			newMu.lock();
			if(conn.event_type_receive()){
				newMu.unlock();
				std::sprintf(msgTmp.buffer,"%s",conn.getPacketData());
				msgTmp.id=conn.getPeerId();
				msgs.push(msgTmp);
			} else newMu.unlock();
			if(conn.event_type_connect()){
				boost::thread newUser(&Server::new_user,this,conn.getPeerId());
				newUser.detach();				//Id we don't do this. The main thread will shutdown after the newUser thread is closed;
			}
			if(conn.event_type_disconnect()){
				std::cout << "Someone disconected!\n";
				if(players[conn.getPeerId()]->getTeam()==RED)
					redTeamN--;
				else
					blueTeamN--;
				delete players[conn.getPeerId()];
				players[conn.getPeerId()]=NULL;
				senderBuffer.type=PROTOCOL_DISCONNECT;
				std::sprintf(senderBuffer.buffer,"%d ",(int16_t)conn.getPeerId());
				conn.broadcast_packet(&senderBuffer,strlen(senderBuffer.buffer)+2);
			}
		}
		dataMu.unlock();
	}
	writeThread->join();
}

void Server::new_user(int id){
	bool done=false;
	_msg msgTmp;
	_data *recieverBuffer;
	_data senderBuffer;
	char buffer[2048];
	int size;
	std::cout << "Someone connected! Id="<<id <<std::endl;

	senderBuffer.type=PROTOCOL_N_PEERS;
	senderBuffer.buffer[0]=users & 0xff;
	senderBuffer.buffer[1]=id & 0xff;
	
	dataMu.lock();
	conn.send_packet_reliable(&senderBuffer,sizeof(senderBuffer),id);
	players[id]=new SCharacter(id);
	dataMu.unlock();
	
	std::cout << "Waiting for his gun..\n";
	
	
	while(!done){
		dataMu.lock();		
		//while(msgs.size()>0){
		if(msgs.size()>0){
			msgTmp=msgs.top();
			if(((_data*)msgTmp.buffer)->type==PROTOCOL_MY_WEAPON && msgTmp.id==id){
				std::stringstream stream;
				int16_t myWeapon;
				stream <<((_data*)msgTmp.buffer)->buffer;
				stream >> myWeapon;
				
				players[id]->setMyWeapon((Weapon)myWeapon);
				msgs.pop();
				done=true;
			}
		}
		dataMu.unlock();
	}
	
	
	std::cout << "Sending the map...\n";
	size=map.serialize(buffer);
	//std::cout << size << " - " << buffer << std::endl;
	
	dataMu.lock();
	conn.send_packet_reliable(buffer,size,id);
	dataMu.unlock();
	
	//Get the spawn area
	std::cout << "Sending the spawn...\n";
	_object* spawn;
	if(blueTeamN>redTeamN){
		bool done=false;
		redTeamN++;
		newMu.lock();
		players[id]->setTeam(RED);
		newMu.unlock();
		while(!done){
			spawn=map.getSpaw();
			if(spawn->r!=0){
				if(map.useSpawn(spawn)){
					std::stringstream stream;
					senderBuffer.type=PROTOCOL_SET_POS_TEAM;
					stream << spawn->x << " " << spawn->y<< " "<<(int16_t)RED<<" ";
					std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
					dataMu.lock();
					conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),id);
					dataMu.unlock();
					done=true;
				}
			}
			
		}
	} else {
		bool done=false;
		blueTeamN++;
		newMu.lock();
		players[id]->setTeam(BLUE);
		newMu.unlock();
		while(!done){
			spawn=map.getSpaw();
			if(spawn->b!=0){
				if(map.useSpawn(spawn)){
					std::stringstream stream;
					senderBuffer.type=PROTOCOL_SET_POS_TEAM;
					stream << spawn->x << " " << spawn->y<< " "<<(int16_t)BLUE<<" ";
					std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
					dataMu.lock();
					conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),id);
					dataMu.unlock();
					done=true;
				}
			}
			
		}
	}
	//send to everyone else that I exist;
	std::stringstream stream;
	senderBuffer.type=PROTOCOL_NEW_USER;
	stream << (int16_t)id << " "  << spawn->x << " " << spawn->y<< " "<<(int16_t)players[id]->getTeam()<<" "<<players[id]->getMyWeapon()<<" ";
	std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
	
	if(players[id]->getMyWeapon()==(int16_t)PISTOL)
		std::cout << "Pistol!\n";
	if(players[id]->getMyWeapon()==(int16_t)RIFLE)
		std::cout << "Rifle!\n";
	
	dataMu.lock();
	for(int i=0;i<users;i++)
		if(players[i]!=NULL && players[i]->getReady()){
			conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),i);
		}
	dataMu.unlock();
	
	//Send who else exists
	senderBuffer.type=PROTOCOL_NEW_USER;
	dataMu.lock();
	for(int i=0;i<users;i++)
		if(players[i]!=NULL && players[i]->getReady()){
			stream=std::stringstream("");
			stream << players[i]->getId() << " "  << players[i]->getX() << " " << players[i]->getY() << " "<<(int16_t)players[i]->getTeam()<<" "<<players[i]->getMyWeapon()<<" ";
			std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
			conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),id);
		}
	
	conn.send_flush();
	dataMu.unlock();
	\
	newMu.lock();
	players[id]->setX(spawn->x);
	players[id]->setY(spawn->y);
	players[id]->make_ready();
	newMu.unlock();
	std::cout << "Client ready to play\n";
}

void Server::user_handle(){
	bool done=false;
	_msg msgTmp;
	_data *recieverBuffer;
	_data senderBuffer;

			
	while(!done){
		dataMu.lock();		//I know, I shouldn't do that.... But fuck that shit.
		if(msgs.size()>0){
			msgTmp=msgs.top();
			if(((_data*)msgTmp.buffer)->type==PROTOCOL_CHARACTER){
				int16_t x,y,dir;
				float angle;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> x >> y >> dir >> angle;
				players[msgTmp.id]->setX(x);
				players[msgTmp.id]->setY(y);
				players[msgTmp.id]->setDir((Direction)dir);
				stream=std::stringstream("");
				for(int i=0;i<users;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_CHARACTER;
						stream << msgTmp.id << " " << x << " " << y << " " << dir << " " << angle << " ";
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_unreliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
				msgs.pop();
				conn.send_flush();
			}
			else if(((_data*)msgTmp.buffer)->type==PROTOCOL_NEW_SHOOT){
				int16_t bulletId,x,y,length,velocity;
				float angle;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> bulletId >> x >> y >>length >>velocity >> angle;
				stream=std::stringstream("");
				for(int i=0;i<users;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_NEW_SHOOT;
						stream << msgTmp.id << " " << bulletId << " " << x << " " << y << " " << length << " " <<velocity << " " <<angle << " ";
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
				msgs.pop();
				conn.send_flush();
			}
			else if(((_data*)msgTmp.buffer)->type==PROTOCOL_DELETE_BULLET){
				int16_t id;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> id;
				stream=std::stringstream("");
				for(int i=0;i<users;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_DELETE_BULLET;
						stream << msgTmp.id << " " << id << " ";
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
					msgs.pop();
				conn.send_flush();
			}
			else if(((_data*)msgTmp.buffer)->type==PROTOCOL_REVIVE){
				int16_t x,y;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> x >>y;
				stream=std::stringstream("");
				for(int i=0;i<users;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_REVIVE;
						stream << msgTmp.id << " " << x << " "<< y << " ";
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
					msgs.pop();
				conn.send_flush();
			}
			else if(((_data*)msgTmp.buffer)->type==PROTOCOL_HIT){
				int16_t bulletId,playerId,dmg;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> bulletId >> playerId >> dmg;
				stream=std::stringstream("");
				for(int i=0;i<users;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_HIT;
						stream << msgTmp.id << " " << bulletId <<" " << playerId <<" " << dmg << " ";
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_reliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
					msgs.pop();
				conn.send_flush();
			}
			
		}
		dataMu.unlock();
	}
}
