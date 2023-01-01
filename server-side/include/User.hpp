#pragma once

#include <cstdint>
#include <string>

class User {
public:
  ~User() = default;
  User(int64_t id, std::string username, std::string password)
      : id_(id), username_(username), password_(password) {}
	
	int64_t getId(){ return id_; }
	
	std::string getUsername(){ return username_; }
	
	std::string getPassword(){ return password_; }

private:
  int64_t id_;
  std::string username_;
  std::string password_;
	bool loggedIn_;
};
