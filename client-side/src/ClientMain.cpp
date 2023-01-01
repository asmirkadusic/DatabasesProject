#include <MessagesData.hpp>
#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/exec_main.hpp>
#include <caf/io/middleman.hpp>
#include <caf/scoped_actor.hpp>
#include <cstdint>
#include <iostream>
#include <caf/all.hpp>
#include <caf/io/all.hpp>
#include <ClientActor.hpp>
#include <ostream>
#include <string>

using namespace std;
using namespace caf;

void menu(){
	cout << "====================================================" << std::endl;
	cout << "Chose option:" << endl;
	cout << "1. Send message to friend" << endl;
	cout << "2. Fetch all active friends" << endl;
	cout << "3. Send message to all active friends" << endl;
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

	std::string username;
	cout << "Please insert your name here: ";
	getline(cin, username);
	scope->send(*server, Messages::LoginMessage{username});
	menu();
	int choice = 1;
	
	cout << "Please insert your intention: ";
	cin >> choice;
	switch (choice) {
		case 1: {
			string message;
			string receiver;
			cout << "Type username of receiver: ";
			cin >> receiver;
			while (true) {
				cout << "Me: ";
				getline(cin, message);
				
				Messages::DirectMessage directMessage;
				directMessage.destination = receiver;
				directMessage.messageValue = message;
				scope->send(*server, directMessage);
				// client->send(*server, directMessage);
				// scope->send(*server, directMessage);
			}
			break;
		}
		case 2: {
			break;
		}
		default: {
			cout << "Default handler for choice " << endl;
		}
	}
}

CAF_MAIN(io::middleman, id_block::ClientMessages);
