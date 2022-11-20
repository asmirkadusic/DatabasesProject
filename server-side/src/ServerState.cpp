#include <ServerState.hpp>

using namespace caf;

behavior ServerBehavior(event_based_actor *) {
  return {[](add_atom, int32_t a, int32_t b) { return a + b; },
          [](sub_atom, int32_t a, int32_t b) { return a - b; }};
}
