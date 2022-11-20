#include <User.hpp>
#include <iostream>

using namespace std;

int main() {
  Common::User user("Asmir", "Kadusic", 1223434, 1234234);
  cout << user.getName() << endl;
  return 0;
}
