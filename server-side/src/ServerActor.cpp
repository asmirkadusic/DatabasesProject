#include "DatabaseTalker.hpp"
#include "ServerMessages.hpp"
#include <ServerActor.hpp>
#include <caf/actor_ostream.hpp>
#include <caf/event_based_actor.hpp>
#include <caf/message_id.hpp>
#include <caf/scheduled_actor.hpp>
#include <caf/stateful_actor.hpp>
#include <caf/system_messages.hpp>
#include <cmath>
#include <string>
#include <sw/redis++/connection.h>
#include <sw/redis++/redis.h>
#include <sw/redis++/redis_cluster.h>

using namespace caf;

behavior ServerActor(caf::stateful_actor<ServerState::Server>* self){	
	self->set_exit_handler(([self](caf::exit_msg msg){
				caf::aout(self) << "Aborting process..." << std::endl;
	}));
	

	return {
		[self](Messages::LoginMessage loginMessage){
			if (self->state.LoggedUsers.find(loginMessage.username) == self->state.LoggedUsers.end()){
				self->state.LoggedUsers.insert({loginMessage.username, loginMessage.myself});
				caf::aout(self) << "Value: " << loginMessage.username << std::endl;
				self->state.conn.set(loginMessage.username, loginMessage.username);		
				self->state.conn.subscriber().subscribe("127.0.0.1");
				self->state.conn.publish("127.0.0.1", loginMessage.username);
			} else {
				self->send(loginMessage.myself, "User with that name already exsists!");
				self->send_exit(loginMessage.myself, caf::none);
			}	
		}
		// iz ovog dijela kada dobijemo poruku od clienta u mainu cemo dalje proslijediti id od clienta, kome se salje poruka i vrijednost poruke.
		// smisliti nacin kako to izvuci iz actora. vjv postoji
	};
}
