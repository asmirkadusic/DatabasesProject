#include <User.hpp>
#include <caf/actor.hpp>

namespace Messages {
struct LoginMessage {
  User name;
  caf::actor myself;
};
}  // namespace Messages
