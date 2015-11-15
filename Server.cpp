#include "Server.hpp"

Server::Server(){
	std::cout << "Creating the server...\n";
	conn.create_server(PORT,MAX_USERS);
	std::cout << "Server created! \nListening to the port " << PORT << std::endl;
	players = new SCharacter*[MAX_USERS];
	for(int i=0;i<MAX_USERS;i++)
		players=NULL;
	
	map.load_map(MAP_FILE);
}

Server::~Server(){
}

void Server::main_loop(){
	bool done=false;
	while(!done){
		while(conn.event_service(WAIT_TIMER)>0){
			if(conn.event_type_connect()){
				std::thread newUser(&Server::new_user,this,conn.getPeerId());
				newUser.detach();
			}
			else if(conn.event_type_disconnect()){
			}
			else if(conn.event_type_receive()){
			}
		}
	}
}

void Server::new_user(int id){
	//players[id]=new SCharacter;
	std::cout << "Someone connected! Id="<<id <<std::endl;
	senderBuffer.type=PROTOCOL_N_PEERS;
	senderBuffer.buffer[0]=MAX_USERS & 0xff;
	senderBuffer.buffer[1]=id & 0xff;
	conn.send_packet_reliable(&senderBuffer,id);
	std::cout << "Sending the map...\n";
	_data tmp=map.send_serial();
	printf("%x%x\n",tmp.buffer[50],tmp.buffer[51]);
	map.get_serial(tmp);
	conn.send_packet_reliable(&tmp,id);
	conn.send_flush();
}
