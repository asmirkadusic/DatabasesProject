#pragma once

#include <caf/actor.hpp>
#include <caf/actor_addr.hpp>
#include <sw/redis++/redis.h>
#include <sw/redis++/redis_cluster.h>
#include <unordered_map>
#include <DatabaseTalker.hpp>
#include <vector>

namespace ServerState {
struct Server {
	std::unordered_map<std::string, caf::actor> LoggedUsers{};
	std::vector<long int> hashedChannels{};
	sw::redis::RedisCluster conn = sw::redis::RedisCluster("tcp://127.0.0.1:7000");
};
}  // namespace ServerState
