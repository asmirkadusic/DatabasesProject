#include <DatabaseTalker.hpp>
#include <iostream>
#include <sw/redis++/redis_cluster.h>

sw::redis::RedisCluster DatabaseTalker::connectToCluster(){
	return sw::redis::RedisCluster("tcp://127.0.0.1:7000");
}

void DatabaseTalker::insertIntoMap(std::string & name, std::string& password){
	try {
		// cluster.set(name, password);				
	} catch (...){
		std::cout << "Exception occured " << std::endl;
	}
}


void DatabaseTalker::getFromDatabase(std::string& key){
	try {
		// std::cout << cluster.redis("key").ping() << std::endl;
		// std::cout << *cluster.get(key) << std::endl;
	} catch (...) {
		std::cout << "Inside catch block in get method " << std::endl;
	}
}
