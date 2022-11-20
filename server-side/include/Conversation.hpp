#pragma once

#include <string>

namespace Common {
class Conversation {
public:
  long getId() { return id_; }
  int getNumberOfParticipants() { return numberOfParticipants_; }

private:
  long id_;
  int numberOfParticipants_;
};
} // namespace Common
