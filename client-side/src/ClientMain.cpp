#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/exec_main.hpp>
#include <caf/io/middleman.hpp>
#include <iostream>
#include <caf/all.hpp>
#include <caf/io/all.hpp>

using namespace std;
using namespace caf;

void caf_main(actor_system& system){
	actor_system_config cfg;
	cfg.load<io::middleman>();

	auto server = system.middleman().remote_actor("localhost", 3000);
	// auto ClientActor = system.spawn();
}

CAF_MAIN(io::middleman);
