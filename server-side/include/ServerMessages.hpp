#pragma once

#include <caf/actor.hpp>
#include <User.hpp>
#include <caf/actor_addr.hpp>
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
		std::string senderName;
		caf::actor_addr sender;
	};
	
	struct RequestForChat {
		std::string usernameForChat;	
		std::string requestSender;
	};
	
} /* Messages */
