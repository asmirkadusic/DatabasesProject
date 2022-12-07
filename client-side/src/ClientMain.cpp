#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/exec_main.hpp>
#include <caf/io/middleman.hpp>
#include <caf/scoped_actor.hpp>
#include <iostream>
#include <caf/all.hpp>
#include <caf/io/all.hpp>
#include <User.hpp>
#include <ClientActor.hpp>

using namespace std;
using namespace caf;

void caf_main(actor_system& system){
	actor_system_config cfg;
	// cfg.add_message_type<Messages::LoginMessage>("Messages::LoginMessage");
	cfg.load<io::middleman>();

	auto server = system.middleman().remote_actor("localhost", 3000);
	auto client = system.spawn(ClientActor, *server);
	scoped_actor scope{system};
	if(server)
		cout << "Server and client connected";
	else 
		cout << "Not connected budalica" << endl;
}

CAF_MAIN(io::middleman);
