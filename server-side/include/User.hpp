#include <cstdint>
#include <string>

class User {
public:
  ~User() = default;
  User(int64_t id, std::string username, std::string password)
      : id_(id), username_(username), password_(password) {}

private:
  int64_t id_;
  std::string username_;
  std::string password_;
};
