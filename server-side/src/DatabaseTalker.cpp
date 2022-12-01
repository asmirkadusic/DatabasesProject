#include <DatabaseTalker.hpp>
#include <sw/redis++/redis_cluster.h>

sw::redis::RedisCluster DatabaseTalker::connectToDatabase(){
	return sw::redis::RedisCluster("tcp://127.0.0.1:7000");
}
