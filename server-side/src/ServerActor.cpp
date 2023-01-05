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
#include <unordered_map>
#include <utility>
#include <vector>

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
			} else {
				caf::aout(self) << "Hash key exists!" << std::endl;
				self->send_exit(loginMessage.myself, caf::none);
			}	
		},
			
		[self](Messages::DirectMessage directMessage){
			auto it = self->state.LoggedUsers.find(directMessage.destination); 
			
			self->state.conn.subscriber().on_message([&self](std::string channel, std::string message){
					caf::aout(self) << "Messagae value is " << message << std::endl;
					});
			
			auto iterator = std::find_if(self->state.hashedChannels.begin(), self->state.hashedChannels.end(), [directMessage](auto&& value){
						return value.second.second == directMessage.senderName || value.second.first == directMessage.senderName;	
					});
			if(iterator != self->state.hashedChannels.end()){
				self->state.conn.publish(std::to_string(iterator->first), directMessage.messageValue);
			}

			if(it != self->state.LoggedUsers.end()){
				// self->send(it->second, directMessage);
				self->state.conn.publish(std::to_string(iterator->first), directMessage.messageValue);
				// self->state.conn.subscriber().consume();
			} else {
				caf::aout(self) << "User with that username is not active" << std::endl;	
			}
		},

		[self](Messages::RequestForChat request){
			auto savedChannels = std::find_if(self->state.hashedChannels.begin(), self->state.hashedChannels.end(),[request](auto&& value){
						return value.second.second == request.requestSender;
					});
			
			if (savedChannels != self->state.hashedChannels.end()){
				self->state.conn.subscriber().subscribe(std::to_string(savedChannels->first));
				caf::aout(self) << "SUBSCRIBED TO CHANNEL " << std::to_string(savedChannels->first) << std::endl;
				self->state.conn.subscriber().on_message([self](std::string message, std::string channel){
						caf::aout(self) << "Message receive" << message << std::endl;
						});
				self->state.conn.subscriber().consume();
				return;
			} 

			auto it = std::find_if(self->state.LoggedUsers.begin(), self->state.LoggedUsers.end(), 
					[request](auto&& value){ return value.first == request.usernameForChat; });
			
			if (it != self->state.LoggedUsers.end()){
				std::pair<std::string, std::string> usernamesForChannels = std::make_pair(request.requestSender, request.usernameForChat);
				std::string valueForHashing = request.usernameForChat + request.requestSender;
				std::hash<std::string> hashValue;
				caf::aout(self) << hashValue(valueForHashing) << std::endl;
				self->state.hashedChannels.insert({hashValue(valueForHashing), usernamesForChannels});
				self->state.conn.subscriber().subscribe(std::to_string(hashValue(valueForHashing)));
				self->state.conn.subscriber().on_message([self](std::string message, std::string channel){
						caf::aout(self) << "Message value " << message << std::endl;
						});
				caf::aout(self) << "CREATED SUBSCRIBER TO CHANNEL " << hashValue(valueForHashing) << std::endl;
			}
		}
	};
}
