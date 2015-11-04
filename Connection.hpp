//Class that handle connection

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <enet/enet.h>
#include <iostream>
#include <string>

class Connection{
	private:
	ENetAddress address;
	ENetHost *conn;
	ENetEvent event;
	bool client; //True if a client was made

	ENetPeer *peer;
	
	//Store useful information of the last comunication.
	ENetAddress lastConnection;
	unsigned int packetLength;
	void *packetData;
	int peerID;
	
	public:
	Connection();
	~Connection();
	
	void perror(std::string error);
	
	void create_server(int port,int num_peers);
	void send_packet_reliable(void *data, int ID);
	void send_packet_unreliable(void *data, int ID);
	void broadcast_packet(void *data);
	void send_flush();

	void event_service(int timer);

	bool event_type_connect();
	bool event_type_receive();
	bool event_type_disconnect();
	bool create_client(std::string ip,int port);
	
	ENetAddress getLastConnection(){return lastConnection;}
	unsigned int getPacketLength(){return packetLength;}
	void* getPacketData(){return packetData;}
	int getPeerId(){return peerID;}
};

#endif