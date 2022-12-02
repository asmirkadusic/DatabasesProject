#include <functional>
#include <string>
class Publisher {
	public:
	void publish(const std::string& message);

	private:
	bool isPublished_{false};	
};
