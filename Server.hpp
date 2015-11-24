#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <string>
#include <stack>
#include <cstring>

#include "Connection.hpp"
#include "SMap.hpp"
#include "IGObject.hpp"
#include "SCharacter.hpp"
#include "Configuration.hpp"
#include "Defines.hpp"

struct _msg{
	char buffer[BUFFER_SIZE];
	int id;
};

class Server{
private:
	Connection conn;
	boost::thread *writeThread;
	boost::thread *cmdThread;
	boost::mutex dataMu;
	boost::mutex newMu;
	boost::mutex cmdMu;		//For using an shell- Not implemented yet!
	
	SMap map;
	SCharacter **players;
	Configuration config;
	
	int redTeamN;
	int blueTeamN;
	int port,users;
	
	std::stack<_msg> msgs;		//Queues are probably better...
	void new_user(int id);
	void user_handle();
public:
	Server();
	~Server();
	void main_loop();
};

#endif
