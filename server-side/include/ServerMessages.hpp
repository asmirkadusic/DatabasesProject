#pragma once

#include <caf/actor.hpp>
#include <User.hpp>
#include <memory>
#include <string>
#include <sw/redis++/redis_cluster.h>

namespace Messages {
	struct LoginMessage{
		std::string username;
		caf::actor myself;
	};

	struct DirectMessage {
		std::string messageValue;
		std::string destination;
		std::string sender;
	};

	struct ClusterStart {
		std::string name;
	};
} /* Messages */
