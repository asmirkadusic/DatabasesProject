#include <caf/actor.hpp>
#include <caf/actor_system.hpp>
#include <caf/actor_system_config.hpp>
#include <iostream>
#include <ServerActor.hpp>
#include <DatabaseTalker.hpp>
#include <sw/redis++/subscriber.h>
#include <caf/io/middleman.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/scoped_actor.hpp>
#include <caf/system_messages.hpp>
#include <caf/io/all.hpp>

using namespace std;
using namespace sw::redis;

int main(){
	// Kada se pokrene cluster i uvezu master nodes s komandom redis-cli create onda ce ovo radiit
	DatabaseTalker cluster;
	auto connection = cluster.connectToCluster();
	connection.set("asmir","kadusic");
	connection.subscriber();
	caf::actor_system_config cfg;
	cfg.load<caf::io::middleman>();
	caf::actor_system system{cfg};
	auto StartServer = system.spawn(ServerActor);
	system.middleman().publish(StartServer, 3000);
	
	// subscriber i publisher ovdje i konekcija s klasterom
	// subscriber na konekciju a publisher na kanal koji cemo dobit kao kombinacija hash usera
	// za sad cemo uzeti da je hash dva id sabrana
	// spawnati actor server ovdje
	// connection.publish(const StringView &channel, StringView &message);
	auto valueFromCluster = connection.get("asmir");
	if(valueFromCluster){
		cout << *valueFromCluster << endl;
	}
}
