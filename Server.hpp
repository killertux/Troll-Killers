#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <mutex>
#include "Connection.hpp"

#define PORT 4665
#define MAX_USERS 16
#define BUFFER_SIZE 1024
#define WAIT_TIMER 1500 

class Server{
private:
	Connection conn;
	char buffer[BUFFER_SIZE];
	std::thread writeThread;
	std::thread cmdThread;
	std::mutex dataMu;
	std::mutex cmdMu;

public:
	Server();
	~Server();
	void main_loop();
};

#endif
