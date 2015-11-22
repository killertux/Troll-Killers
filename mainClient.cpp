#include "Client.hpp"

int main(){
	Client client;
	/*if(!client.connect()){
		std::cout << "Deu merda!\n";
		
	} else
		client.main_loop();*/
	client.menu();
	return 0;
}