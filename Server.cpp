#include "Server.hpp"

Server::Server(){
	conn.create_server(PORT,MAX_USERS);
}

Server::~Sever(){
}

void Server::main_loop(){
	bool done=false;
	while(!done){
		while(conn.event_service(WAIT_TIMER)!=0){
			
		}
	}
}
