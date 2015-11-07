#include "Connection.hpp"

//Construct and Destruct

Connection::Connection(){
	if(enet_initialize() != 0 )
		perror("Error while initializing enet!");
	
}

Connection::~Connection(){
	if(!client){
		int i;
		for(i=0;i<=sizeof(conn->peers);i++)
			enet_peer_disconnect(&conn->peers[i],0);
		enet_host_service (conn, & event, 3000);
	}else{
		enet_peer_disconnect(peer,0);
		enet_host_service (conn, & event, 3000);
	}
	enet_host_destroy(conn);
	enet_deinitialize();
}

//Methods

void Connection::create_server(int port,int num_peers){
	address.host=ENET_HOST_ANY;
	address.port=port;
	conn = enet_host_create(& address, num_peers,2,0,0);
	if (conn == NULL)
		perror("Enet creating server error!");
	client=false;
}

void Connection::send_packet_reliable(void *data,int ID){
	ENetPacket *packet = enet_packet_create (data, sizeof(data), ENET_PACKET_FLAG_RELIABLE);
	if(!client)
		enet_peer_send (&conn->peers[ID], 0, packet);
	else
		enet_peer_send(peer,0,packet);
}

void Connection::send_packet_unreliable(void *data,int ID){
	ENetPacket *packet = enet_packet_create (data, sizeof(data), ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
	if(!client)
		enet_peer_send (&conn->peers[ID], 0, packet);
	else
		enet_peer_send(peer,0,packet);
}

void Connection::broadcast_packet(void *data){
	if(!client){
		ENetPacket *packet = enet_packet_create (data, sizeof(data), ENET_PACKET_FLAG_RELIABLE);
		enet_host_broadcast (conn, 0, packet);
	} else
		std::cout << "Warn! Client can't broadcast!\n";
}

void Connection::send_flush(){
    enet_host_flush(conn);
}

int Connection::event_service(int timer){
	int retr;
	if(!(retr=enet_host_check_events (conn,&event)))			//Get an event from the stack.
		retr=enet_host_service(conn, &event,timer);			//If one is not avalible, wait 'timer' miliseconds for one.
	if(event.type==ENET_EVENT_TYPE_CONNECT){
		lastConnection.host = event.peer -> address.host;
		lastConnection.port = event.peer -> address.port;
		peerID=event.peer -> incomingPeerID;
	} else if(event.type==ENET_EVENT_TYPE_RECEIVE){
		lastConnection.host = event.peer -> address.host;
		lastConnection.port = event.peer -> address.port;
		peerID=event.peer -> incomingPeerID;

		packetLength = event.packet -> dataLength;
		packetData = event.packet -> data;
	} else if(event.type==ENET_EVENT_TYPE_DISCONNECT){
		lastConnection.host = event.peer -> address.host;
		lastConnection.port = event.peer -> address.port;
		peerID=event.peer -> incomingPeerID;
	}
	return retr;
}

void Connection::perror(std::string error){
	std::cout << error << std::endl;
	exit(-1);
}

bool Connection::event_type_connect(){
	if(event.type==ENET_EVENT_TYPE_CONNECT)
		return true;
	return false;
}

bool Connection::event_type_receive(){
	if(event.type==ENET_EVENT_TYPE_RECEIVE)
		return true;
	return false;
}

bool Connection::event_type_disconnect(){
	if(event.type==ENET_EVENT_TYPE_DISCONNECT)
		return true;
	return false;
}

bool Connection::create_client(std::string ip,int port){
	conn=enet_host_create(NULL,1,2,57600 / 8,14400 / 8);
	if (conn == NULL)
	perror("Erro creating the client");

	enet_address_set_host(&address,ip.c_str());
	address.port=port;
	peer= enet_host_connect(conn,&address,2,0);
	if (peer == NULL)
		perror("Error connecting to server!");

	if(enet_host_service(conn,&event,5000)>0 && event.type == ENET_EVENT_TYPE_CONNECT){
		client=true;
		return true;
	} else
		return false;
}