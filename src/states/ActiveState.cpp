#include "ActiveState.h"

using namespace gameModule;

ActiveState::ActiveState(std::array<std::deque<Slot>, 4>& slots) :
    State(slots)
{
    for (auto& drum : slots)
    {
	drum[m_slotToUpdate].changeType(drum[m_slotToUpdate].getType());
    }
}

bool ActiveState::update(float dt) 
{   
    if (m_timer > 0.0f)
    {
	for (auto& drum : m_slots)
	{
	    for (unsigned int slot = 0; slot < drum.size(); slot++)
	    {
		drum[slot].m_position.y += m_velocity * dt;
		if (drum[slot].m_position.y > m_downPosY)
		{
		    
		}
	    }
	}
	m_timer -= dt;
	return true;
    }
    m_timer = 5.0f;
    return false;
   
}

StateType ActiveState::getType() const
{
    return StateType::Active;
}
