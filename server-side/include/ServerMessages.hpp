#pragma once

#include <caf/actor.hpp>
#include <User.hpp>
#include <string>

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

} /* Messages */
