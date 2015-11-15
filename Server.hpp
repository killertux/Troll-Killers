#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <mutex>
#include "Connection.hpp"
#include "Map.hpp"
#include "IGObject.hpp"
#include "SCharacter.hpp"
#include <cstring>
#include "Defines.hpp"
#include <string>

#define PORT 4665
#define MAX_USERS 16
#define WAIT_TIMER 1500
#define MAP_FILE "../Maps/mapa.data"

class Server{
private:
	Connection conn;
	std::thread writeThread;
	std::thread cmdThread;
	std::mutex dataMu;
	std::mutex cmdMu;
	
	Map map;
	SCharacter **players;
	
	_data *recieverBuffer;
	_data senderBuffer;
	void new_user(int id);
public:
	Server();
	~Server();
	void main_loop();
};

#endif
