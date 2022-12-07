#pragma once

#include <caf/actor.hpp>
#include <unordered_map>

namespace ServerState {
struct Server {
  std::unordered_map<std::string, caf::actor> LoggedUsers{};
};
}  // namespace ServerState
