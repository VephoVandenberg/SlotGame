#include "State.h"

using namespace gameModule;

State::State(std::array<std::deque<Slot>, 4>& slots) :
    m_slots(slots)
{
    
}
