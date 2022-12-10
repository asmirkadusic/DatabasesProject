#pragma once

#include <functional>
#include <sw/redis++/subscriber.h>
#include <type_traits>

class Subscriber {
	public:
	~Subscriber() = default;
	Subscriber(std::string&);
	void subscribe(std::function<void>);
	void unsubscribe(std::function<void>);

	private:
	sw::redis::Subscriber& subscriber_;
};
