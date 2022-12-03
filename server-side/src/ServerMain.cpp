#include <iostream>
#include <DatabaseTalker.hpp>
#include <sw/redis++/subscriber.h>

using namespace std;
using namespace sw::redis;

int main(){
	// Kada se pokrene cluster i uvezu master nodes s komandom redis-cli create onda ce ovo radiit
	DatabaseTalker cluster;
	auto connection = cluster.connectToCluster();
	connection.set("asmir","kadusic");
	connection.subscriber();
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
