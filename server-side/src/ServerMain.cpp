#include <caf/exec_main.hpp>
#include <caf/init_global_meta_objects.hpp>
#include <sw/redis++/subscriber.h>

#include <DatabaseTalker.hpp>
#include <ServerActor.hpp>
#include <caf/actor.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <caf/io/all.hpp>
#include <caf/io/middleman.hpp>
#include <caf/scoped_actor.hpp>
#include <caf/system_messages.hpp>
#include <caf/init_global_meta_objects.hpp>
#include <iostream>

using namespace std;
using namespace sw::redis;
using namespace caf;

void caf_main(actor_system& system) {
  // Kada se pokrene cluster i uvezu master nodes s komandom redis-cli create
  // onda ce ovo radiit
  // DatabaseTalker cluster;
  // auto connection = cluster.connectToCluster();

  // connection.set("asmir", "kadusic");
  // connection.subscriber();
  actor_system_config cfg;
  cfg.load<caf::io::middleman>();
  auto StartServer = system.spawn(ServerActor);
  system.middleman().publish(StartServer, 3000);
	if(!StartServer){
		cerr << "Actor not spawned. Please try again!" << endl;
		return;
	} else {
		cout << "Server started successfully!" << endl;
	}
	while(true){}
	// subscriber i publisher ovdje i konekcija s klasterom
  // subscriber na konekciju a publisher na kanal koji cemo dobit kao
  // kombinacija hash usera za sad cemo uzeti da je hash dva id sabrana spawnati
  // actor server ovdje connection.publish(const StringView &channel, StringView
  // &message);
}

CAF_MAIN(io::middleman);
