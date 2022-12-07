#include <Messages.hpp>
#include <caf/actor.hpp>
#include <caf/all.hpp>
#include <caf/detail/pretty_type_name.hpp>
#include <caf/fwd.hpp>
#include <caf/inspector_access.hpp>
#include <caf/inspector_access_type.hpp>
#include <caf/message.hpp>
#include <caf/type_id.hpp>

namespace Messages {

template <class Inspector>
bool inspect(Inspector& f, LoginMessage& x) {
	return f.object(x).fields(f.field("name", x.name), f.field("myself", x.myself));
}
}  // namespace Messages
