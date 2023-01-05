#include "ClientState.hpp"
#include <ClientActor.hpp>
#include <MessagesData.hpp>
#include <caf/actor_cast.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/behavior.hpp>
#include <caf/event_based_actor.hpp>
#include <caf/exit_reason.hpp>
#include <caf/scheduled_actor.hpp>
#include <caf/stateful_actor.hpp>
#include <caf/system_messages.hpp>
#include <caf/type_id.hpp>
#include <chrono>
#include <cstdint>

caf::behavior ClientActor(caf::stateful_actor<Client>* self,
			  caf::actor destination) {
  self->set_exit_handler(([self](caf::exit_msg) {
    caf::aout(self) << "Exiting from client side..." << std::endl;
  }));

  return {
      [self](Messages::LoginMessage msg) { 
				caf::aout(self) << "You are logged in as: " << msg.name << std::endl;
			},

			[self](std::string value){
					caf::aout(self) << value << std::endl;
			},

			[self](Messages::DirectMessage value){
				caf::aout(self) << "========================================" << std::endl;
				caf::aout(self) << value.senderName << ": " << value.messageValue << std::endl;
				caf::aout(self) << "========================================" << std::endl;
			},

			[self](Messages::ChatParticipant msg){
				caf::aout(self) << msg.chatChannel << std::endl;
				self->state.pairedUsers.insert({msg.withThisUser, msg.chatChannel});	
			}
};}
