#include <caf/all.hpp>
#include <caf/behavior.hpp>
#include <caf/event_based_actor.hpp>
#include <MessageData.hpp>
#include <caf/stateful_actor.hpp>
#include <ServerState.hpp>

caf::behavior ServerActor(caf::stateful_actor<ServerState::Server>*);
