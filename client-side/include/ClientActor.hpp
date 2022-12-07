#pragma once

#include <caf/stateful_actor.hpp>

struct Client {
	std::string message{""};
};

caf::behavior ClientActor(caf::stateful_actor<Client>*, caf::actor dest);
