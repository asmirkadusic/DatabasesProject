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
      [self](std::string message) { 
				caf::aout(self) << message << std::endl;
			}
};}
