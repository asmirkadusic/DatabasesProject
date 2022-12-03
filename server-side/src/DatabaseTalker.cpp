#include <DatabaseTalker.hpp>
#include <sw/redis++/redis_cluster.h>

sw::redis::RedisCluster DatabaseTalker::connectToCluster(){
	return sw::redis::RedisCluster("tcp://127.0.0.1:7000");
}
