#include <User.hpp>
#include <caf/actor.hpp>

namespace Messages {
struct LoginMessage {
	std::string name;
  caf::actor myself;
};
}  // namespace Messages
