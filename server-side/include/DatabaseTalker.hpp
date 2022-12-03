#include <sw/redis++/connection.h>
#include <sw/redis++/redis++.h>
#include <Publisher.hpp>
#include <Subscriber.hpp>

class DatabaseTalker {
	public:
		~DatabaseTalker() = default;
		sw::redis::RedisCluster connectToCluster();
		void disconnectFromCluster();
	
	private:
	bool isConnected_{false};
};

