#pragma once

#include <caf/stateful_actor.hpp>
#include <unordered_map>
#include <vector>

struct Client {
	std::unordered_map<std::string, size_t> pairedUsers{};
};

caf::behavior ClientActor(caf::stateful_actor<Client>*, caf::actor dest);
