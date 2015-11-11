#include "Server.hpp"

Server::Server(){
	std::cout << "Creating the server...\n";
	conn.create_server(PORT,MAX_USERS);
	std::cout << "Server created! \nListening to the port " << PORT << std::endl;
}

Server::~Server(){
}

void Server::main_loop(){
	bool done=false;
	while(!done){
		while(conn.event_service(WAIT_TIMER)>0){
			if(conn.event_type_connect()){
			}
			else if(conn.event_type_disconnect()){
			}
			else if(conn.event_type_receive()){
			}
		}
	}
}
