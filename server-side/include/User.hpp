#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace Common {
class User {
public:
  User(std::string name, std::string surname, long id, long phoneNumber)
      : name_(name), surname_(surname), id_(id), phoneNumber_(phoneNumber) {}
  std::string getName() { return name_; }
  std::string getSurname() { return surname_; }
  long phoneNumber() { return phoneNumber_; }

private:
  std::string name_{"Asmir je kralj"};
  std::string surname_;
  long id_;
  long phoneNumber_;
};
} // namespace Common
