#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <mutex>
#include "Connection.hpp"
#include "SMap.hpp"
#include "IGObject.hpp"
#include "SCharacter.hpp"
#include <cstring>
#include "Defines.hpp"
#include <string>
#include <stack>

#define PORT 4665
#define MAX_USERS 16
#define WAIT_TIMER 1500
#define MAP_FILE "../Maps/mapa.data"

struct _msg{
	char buffer[BUFFER_SIZE];
	int id;
};

class Server{
private:
	Connection conn;
	std::thread *writeThread;
	std::thread *cmdThread;
	std::mutex dataMu;
	std::mutex newMu;
	std::mutex cmdMu;
	
	SMap map;
	SCharacter **players;
	
	int redTeamN;
	int blueTeamN;
	
	std::stack<_msg> msgs;
	_data *recieverBuffer;
	_data senderBuffer;
	void new_user(int id);
	void user_handle();
public:
	Server();
	~Server();
	void main_loop();
};

#endif
