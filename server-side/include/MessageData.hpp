#pragma once

#include <ServerMessages.hpp>
#include <caf/actor.hpp>
#include <caf/type_id.hpp>

CAF_BEGIN_TYPE_ID_BLOCK(ServerMessages, first_custom_type_id)

CAF_ADD_TYPE_ID(ServerMessages, (Messages::LoginMessage))

CAF_ADD_TYPE_ID(ServerMessages, (Messages::DirectMessage))

CAF_ADD_TYPE_ID(ServerMessages, (Messages::RequestForChat))

CAF_ADD_TYPE_ID(ServerMessages, (Messages::ChatParticipant))

CAF_END_TYPE_ID_BLOCK(ServerMessages)

namespace Messages {
template <class Inspector>
bool inspect(Inspector& f, Messages::LoginMessage& x) {
  return f.object(x).fields(f.field("username", x.username),
			    f.field("myself", x.myself));
};

template <class Inspector>
bool inspect(Inspector& f, Messages::DirectMessage& x) {
  return f.object(x).fields(f.field("messageValue", x.messageValue),
			    f.field("destination", x.destination),
			    f.field("senderName", x.senderName),
			    f.field("sender", x.sender));
};

template <class Inspector>
bool inspect(Inspector& f, Messages::RequestForChat& x) {
  return f.object(x).fields(f.field("usernameForChat", x.usernameForChat),
			    f.field("requestSender", x.requestSender));
};

template <class Inspector>
bool inspect(Inspector& f, Messages::ChatParticipant& x){
	return f.object(x).fields(f.field("withUser", x.withThisUser), f.field("channel", x.chatChannel));
}

}  // namespace Messages
