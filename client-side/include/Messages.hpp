#include <User.hpp>
#include <caf/actor.hpp>
#include <caf/actor_addr.hpp>

namespace Messages {
struct LoginMessage {
	std::string name;
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

}  // namespace Messages
