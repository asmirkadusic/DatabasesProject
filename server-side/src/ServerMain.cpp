#include "ServerMessages.hpp"
#include <sw/redis++/subscriber.h>
#include <DatabaseTalker.hpp>
#include <ServerActor.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/io/all.hpp>
#include <caf/io/middleman.hpp>
#include <caf/scoped_actor.hpp>
#include <caf/system_messages.hpp>
#include <iostream>

using namespace std;
using namespace sw::redis;
using namespace caf;

void caf_main(actor_system& system) {
  // Kada se pokrene cluster i uvezu master nodes s komandom redis-cli create
  // onda ce ovo radiit

	actor_system_config cfg;
	cfg.load<caf::io::middleman>();
	auto host = get_if<std::string>(&cfg, "database.host");
	auto startServer = system.spawn(ServerActor);
  system.middleman().publish(startServer, 3000);
	
	scoped_actor scope{system};
	if(!startServer){
	 	cerr << "Actor not spawned. Please try again!" << endl;
		return;
	 } else {
		 cout << "Server started successfully!" << endl;
	}
		
	while(true){}
}

CAF_MAIN(io::middleman, id_block::ServerMessages);
