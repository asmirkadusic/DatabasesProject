#include <ServerActor.hpp>
#include <DatabaseTalker.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/event_based_actor.hpp>
#include <caf/message_id.hpp>
#include <caf/scheduled_actor.hpp>
#include <caf/stateful_actor.hpp>
#include <caf/system_messages.hpp>
#include <cmath>

using namespace caf;

behavior ServerActor(caf::stateful_actor<ServerState::Server>* self){
	
	self->set_exit_handler(([self](caf::exit_msg msg){
				caf::aout(self) << "Aborting process..." << std::endl;
				}));

	return {
		[self](Messages::LoginMessage loginMessage){
			if (self->state.LoggedUsers.find(loginMessage.username) == self->state.LoggedUsers.end()){
				self->state.LoggedUsers.insert({loginMessage.username, loginMessage.myself});
			} else {
				self->send(loginMessage.myself, "User with that name already exsists!");
				self->send_exit(loginMessage.myself, caf::none);
			}	
		}
		// iz ovog dijela kada dobijemo poruku od clienta u mainu cemo dalje proslijediti id od clienta, kome se salje poruka i vrijednost poruke.
		// smisliti nacin kako to izvuci iz actora. vjv postoji
	};
}
