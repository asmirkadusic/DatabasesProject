#pragma once

#include <functional>
#include <string>

class Publisher {
	public:
	~Publisher() = default;
	void publish(const std::string& message);

	private:
	bool isPublished_{false};	
};
