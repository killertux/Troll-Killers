#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <mutex>
#include "Connection.hpp"
#include "Map.hpp"
#include "IGObject.hpp"
#include "SCharacter.hpp"

#define PORT 4665
#define MAX_USERS 16
#define WAIT_TIMER 1500 

class Server{
private:
	Connection conn;
	std::thread writeThread;
	std::thread cmdThread;
	std::mutex dataMu;
	std::mutex cmdMu;
	
	Map map;
	SCharacter **players;

public:
	Server();
	~Server();
	void main_loop();
};

#endif
