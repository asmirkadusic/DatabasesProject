#include <functional>
#include <sw/redis++/subscriber.h>
#include <type_traits>
class Subscriber {
	public:
	void subscribe(std::function<void>);
	void unsubscribe(std::function<void>);

	private:
	sw::redis::Subscriber subscriber_;
};
