#pragma once

#include <memory>
#include <sw/redis++/connection.h>
#include <sw/redis++/redis++.h>

#include <Publisher.hpp>
#include <Subscriber.hpp>
#include <caf/actor.hpp>
#include <sw/redis++/redis_cluster.h>
#include <unordered_map>
#include <utility>

class DatabaseTalker {
 public:
  DatabaseTalker(bool value) : isConnected_(value) {}
	~DatabaseTalker() = default;
  sw::redis::RedisCluster connectToCluster();
  void disconnectFromCluster();
	void insertIntoMap(std::string&, std::string&);
	void getFromDatabase(std::string&);
	
	int size;
  std::unordered_map<std::string, caf::actor> LoggedUsers{};
 private:
  
	bool isConnected_{false};
	// sw::redis::RedisCluster cluster;
};

