#pragma once

#include <Messages.hpp>
#include <caf/type_id.hpp>

CAF_BEGIN_TYPE_ID_BLOCK(ClientMessages, first_custom_type_id)

	CAF_ADD_TYPE_ID(ClientMessages, (Messages::LoginMessage))

	CAF_ADD_TYPE_ID(ClientMessages, (Messages::DirectMessage))

	CAF_ADD_TYPE_ID(ClientMessages, (Messages::RequestForChat))

CAF_END_TYPE_ID_BLOCK(ClientMessages)

namespace Messages {

template <class Inspector>
bool inspect(Inspector& f, LoginMessage& x) {
	return f.object(x).fields(f.field("name", x.name), f.field("myself", x.myself));
}

template <class Inspector>
bool inspect(Inspector& f, DirectMessage& x){
	return f.object(x).fields(f.field("messageValue", x.messageValue), f.field("destination", x.destination), f.field("senderName", x.senderName), f.field("sender", x.sender));
}

template <class Inspector>
bool inspect(Inspector& f, RequestForChat& x){
	return f.object(x).fields(f.field("Request", x.usernameForChat), f.field("RequestSender", x.requestSender));
}

}  // namespace Messages
