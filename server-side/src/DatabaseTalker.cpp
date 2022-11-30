#include <DatabaseTalker.hpp>

sw::redis::Redis DatabaseTalker::connectToDatabase(){
	auto redis = sw::redis::Redis("tcp://127.0.0.1:7000");
	isConnected = true;
	return redis;
}
