#include <ServerActor.hpp>

using namespace caf;

behavior ServerActor(event_based_actor* self){
	return {
		// iz ovog dijela kada dobijemo poruku od clienta u mainu cemo dalje proslijediti id od clienta, kome se salje poruka i vrijednost poruke.
		// smisliti nacin kako to izvuci iz actora. vjv postoji
	};
}
