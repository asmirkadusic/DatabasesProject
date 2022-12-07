#include <User.hpp>
#include <caf/actor.hpp>

namespace Messages {
struct LoginMessage {
	std::string name;
  caf::actor myself;
};

struct DirectMessage {
	std::string messageValue;
	std::string destination;
	caf::actor sender;
};

}  // namespace Messages
