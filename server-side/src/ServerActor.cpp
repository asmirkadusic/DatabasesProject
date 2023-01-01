#include "DatabaseTalker.hpp"
#include "ServerMessages.hpp"
#include <ServerActor.hpp>
#include <algorithm>
#include <caf/actor_ostream.hpp>
#include <caf/event_based_actor.hpp>
#include <caf/message_id.hpp>
#include <caf/scheduled_actor.hpp>
#include <caf/stateful_actor.hpp>
#include <caf/system_messages.hpp>
#include <chrono>
#include <cmath>
#include <functional>
#include <iterator>
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
			std::string key = loginMessage.username;
			std::hash<std::string> hashForUsername;
			std::string keyValue = std::to_string(hashForUsername(loginMessage.username));
			if (!self->state.conn.get(keyValue).has_value()){
				self->state.conn.set(keyValue, loginMessage.username);
				self->state.LoggedUsers.insert({loginMessage.username, loginMessage.myself});
				caf::aout(self) << keyValue << std::endl;
			} else {
				caf::aout(self) << "Hash key exists!" << std::endl;
				self->send_exit(loginMessage.myself, caf::none);
			}	
		},
		
		[self](Messages::DirectMessage directMessage){
			auto it = self->state.LoggedUsers.find(directMessage.destination); 
			for(auto pair : self->state.LoggedUsers){
				caf::aout(self) << pair.first << ": " << pair.second << std::endl;
			}
			if(it != self->state.LoggedUsers.end()){
				caf::aout(self) << "Inside if condition" << std::endl;
				self->send(it->second, directMessage);
			} else {
				caf::aout(self) << "User with that username is not active" << std::endl;	
			}
		}
	};
}
