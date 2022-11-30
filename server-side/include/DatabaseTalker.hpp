#include <sw/redis++/redis++.h>

class DatabaseTalker {
	public:
		sw::redis::Redis connectToDatabase();

	private:
	bool isConnected{false};
};

