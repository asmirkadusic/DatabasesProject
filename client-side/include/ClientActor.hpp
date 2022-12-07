#pragma once

#include <caf/all.hpp>
#include <caf/behavior.hpp>
#include <caf/event_based_actor.hpp>
#include <caf/stateful_actor.hpp>
#include <cstdlib>

struct Client {
	std::string message{""};
};

caf::behavior ClientActor(caf::stateful_actor<Client>*, caf::actor dest);
