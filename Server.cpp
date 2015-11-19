#include "Server.hpp"

Server::Server(){
	std::cout << "Creating the server...\n";
	conn.create_server(PORT,MAX_USERS);
	std::cout << "Server created! \nListening to the port " << PORT << std::endl;
	players = new SCharacter*[MAX_USERS];
	for(int i=0;i<MAX_USERS;i++)
		players[i]=NULL;
	
	map.load_map(MAP_FILE);
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
	bool done=false;
	writeThread=new boost::thread(&Server::user_handle,this);
	while(!done){
		dataMu.lock();
		while(conn.event_service(1/FPS)>0){
			newMu.lock();
			if(conn.event_type_receive() && players[conn.getPeerId()]!=NULL && players[conn.getPeerId()]->getReady()){
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
				delete players[conn.getPeerId()];
				players[conn.getPeerId()]=NULL;
			}
		}
		dataMu.unlock();
	}
	writeThread->join();
}

void Server::new_user(int id){
	//players[id]=new SCharacter;
	_data *recieverBuffer;
	_data senderBuffer;
	char buffer[2048];
	int size;
	std::cout << "Someone connected! Id="<<id <<std::endl;

	senderBuffer.type=PROTOCOL_N_PEERS;
	senderBuffer.buffer[0]=MAX_USERS & 0xff;
	senderBuffer.buffer[1]=id & 0xff;
	
	dataMu.lock();
	conn.send_packet_reliable(&senderBuffer,sizeof(senderBuffer),id);
	players[id]=new SCharacter(id);
	dataMu.unlock();
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
	stream << (int16_t)id << " "  << spawn->x << " " << spawn->y<< " "<<(int16_t)players[id]->getTeam()<<" ";
	std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
	
	dataMu.lock();
	for(int i=0;i<MAX_USERS;i++)
		if(players[i]!=NULL && players[i]->getReady()){
			conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),i);
		}
	dataMu.unlock();
	
	senderBuffer.type=PROTOCOL_NEW_USER;
	dataMu.lock();
	for(int i=0;i<MAX_USERS;i++)
		if(players[i]!=NULL && players[i]->getReady()){
			stream=std::stringstream("");
			stream << players[i]->getId() << " "  << players[i]->getX() << " " << players[i]->getY() << " "<<(int16_t)players[i]->getTeam()<<" ";
			std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
			conn.send_packet_reliable(&senderBuffer,(int)sizeof(senderBuffer),id);
		}
	
	conn.send_flush();
	dataMu.unlock();
	
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
		while(msgs.size()>0){
			msgTmp=msgs.top();
			msgs.pop();
			if(((_data*)msgTmp.buffer)->type==PROTOCOL_CHARACTER){
				int16_t x,y,dir;
				std::stringstream stream;
				stream << ((_data*)msgTmp.buffer)->buffer;
				stream >> x >> y >> dir;
				players[msgTmp.id]->setX(x);
				players[msgTmp.id]->setY(y);
				players[msgTmp.id]->setDir((Direction)dir);
				stream=std::stringstream("");
				for(int i=0;i<MAX_USERS;i++)
					if(i!=msgTmp.id && players[i]!=NULL && players[i]->getReady()){
						senderBuffer.type=PROTOCOL_CHARACTER;
						stream << msgTmp.id << " " << x << " " << y << " " << dir << " " ;
						std::sprintf(senderBuffer.buffer,"%s",stream.str().c_str());
						conn.send_packet_unreliable(&senderBuffer,strlen(senderBuffer.buffer)+2,i);
					}
				conn.send_flush();
			}
		}
		dataMu.unlock();
	}
}
