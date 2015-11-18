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
	writeThread=new std::thread(&Server::user_handle,this);
	while(!done){
		while(conn.event_service(WAIT_TIMER)>0){
			dataMu.lock();
			if(conn.event_type_connect()){
				std::thread newUser(&Server::new_user,this,conn.getPeerId());
				newUser.detach();
			}
			else if(conn.event_type_disconnect()){
				std::cout << "Someone disconected!\n";
				delete players[conn.getPeerId()];
				players[conn.getPeerId()]=NULL;
			}
			else if(conn.event_type_receive()){
				std::cout << "Received a message\n";
				std::sprintf(msgTmp.buffer,"%s",conn.getPacketData());
				msgTmp.id=conn.getPeerId();
			}
			dataMu.unlock();
		}
	}
}

void Server::new_user(int id){
	//players[id]=new SCharacter;
	char buffer[2048];
	int size;
	std::cout << "Someone connected! Id="<<id <<std::endl;
	senderBuffer.type=PROTOCOL_N_PEERS;
	senderBuffer.buffer[0]=MAX_USERS & 0xff;
	senderBuffer.buffer[1]=id & 0xff;
	
	dataMu.lock();
	conn.send_packet_reliable(&senderBuffer,sizeof(senderBuffer),id);
	newMu.lock();
	players[id]=new SCharacter(id);
	newMu.unlock();
	dataMu.unlock();
	std::cout << "Sending the map...\n";
	size=map.serialize(buffer);
	//std::cout << size << " - " << buffer << std::endl;
	
	dataMu.lock();
	conn.send_packet_reliable(buffer,size,id);
	conn.send_flush();
	dataMu.unlock();
	
	//Get the spawn area
	newMu.lock();
	std::cout << "Sending the spawn...\n";
	_object* spawn;
	if(blueTeamN>redTeamN){
		bool done=false;
		redTeamN++;
		players[id]->setTeam(RED);
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
		players[id]->setTeam(BLUE);
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
	players[id]->setX(spawn->x);
	players[id]->setY(spawn->y);
	conn.send_flush();
	newMu.unlock();
	players[id]->make_ready();
	std::cout << "Client ready to play\n";
}

void Server::user_handle(){

}
