#include <sw/redis++/connection.h>
#include <sw/redis++/redis++.h>
#include <sw/redis++/redis_cluster.h>

class DatabaseTalker {
	public:
		sw::redis::RedisCluster connectToDatabase();
		void disconnectFromDatabase();
	
	private:
	bool isConnected_{false};
};

