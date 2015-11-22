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

#define MAP_FILE "Maps/mapa.data"
//#define MAP_FILE "Maps/mapa.data"

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
	boost::mutex cmdMu;
	
	SMap map;
	SCharacter **players;
	Configuration config;
	
	int redTeamN;
	int blueTeamN;
	int port,users;
	
	std::stack<_msg> msgs;
	void new_user(int id);
	void user_handle();
public:
	Server();
	~Server();
	void main_loop();
};

#endif
