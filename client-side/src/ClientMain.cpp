#include <MessagesData.hpp>
#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/exec_main.hpp>
#include <caf/io/middleman.hpp>
#include <caf/scoped_actor.hpp>
#include <iostream>
#include <caf/all.hpp>
#include <caf/io/all.hpp>
#include <ClientActor.hpp>
#include <string>

using namespace std;
using namespace caf;

void menu(){
	cout << "====================================================" << std::endl;
	cout << "Chose option:" << endl;
	cout << "1. Send message to friend" << endl;
	cout << "====================================================" << std::endl;
}

void caf_main(actor_system& system){
	actor_system_config cfg;
	cfg.load<io::middleman>();

	auto server = system.middleman().remote_actor("localhost", 3000);
	auto client = system.spawn(ClientActor, *server);
	scoped_actor scope{system};
	
	if(!server){
		cout << "Server is not running!";
		return;
	}

	menu();
	std::string username;
	cout << "Please insert your name here: ";
	getline(cin, username);
	scope->send(*server, Messages::LoginMessage{username});
}

CAF_MAIN(io::middleman, id_block::ClientMessages);
