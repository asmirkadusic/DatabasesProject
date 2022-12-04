#include <ClientActor.hpp>
#include <MessagesData.hpp>
#include <caf/behavior.hpp>
#include <caf/event_based_actor.hpp>
#include <chrono>

caf::behavior ClientActor(caf::event_based_actor* self, caf::actor destination){
	return {
		// [self,destination](Messages::LoginMessage loginData){
		// 	loginData.myself = self;
		//	self->request(destination, std::chrono::seconds{1}, Messages::LoginMessage{loginData});
	};
}
