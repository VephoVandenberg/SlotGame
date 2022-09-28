#include <algorithm>
#include <random>

#include "ActiveState.h"

using namespace gameModule;

ActiveState::ActiveState(std::array<std::deque<Slot>, 4>& slots) :
    State(slots)
{
    int index = 0;
    for (auto& drum : slots)
    {
	drum[m_slotToUpdate].changeType(drum[m_slotToUpdate].getType());
	m_maxVelocities.push_back(20*(index++) + 300);
    }

    
    m_velocities = std::vector<float>(m_maxVelocities.size(), 3.0f);
}

bool ActiveState::update(float dt) 
{
    int index = 0;
    if (m_timer > 0.0f)
    {
	for (auto& drum : m_slots)
	{
	    m_velocities[index] += (m_velocities[index] < m_maxVelocities[index]) ? 2.0f : 0.0f;
	    for (unsigned int slot = 0; slot < drum.size(); slot++)
	    {
		drum[slot].m_position.y += m_velocities[index] * dt;
		if (drum[slot].m_position.y >= m_downPosY)
		{
		    auto temp = drum[slot];
		    drum.pop_back();
		    temp.m_position.y = m_upPosY;
		    drum.push_front(temp);
		}
	    }
	    index++;
	}
	m_timer -= dt;
	return true;
    }
    
    bool stateNotReady = false;
    index = 0;
    for (auto& drum : m_slots)
    {
	if (drum[0].m_position.y > m_upPosY || m_velocities[index] > 15.0f)
	{
	    m_velocities[index] -= (m_velocities[index] > 15.0f) ? 3.0f : 0.0f;
	    for (unsigned int slot = 0; slot < drum.size(); slot++)
	    {
		drum[slot].m_position.y += m_velocities[index] * dt;
		if (drum[slot].m_position.y >= m_downPosY)
		{
		    auto temp = drum[slot];
		    drum.pop_back();
		    temp.m_position.y = m_upPosY;
		    drum.push_front(temp);
		}
	    }
	    stateNotReady = true;
	}
	else
	{
	    // Align slots
	    glm::vec2 slotSize = drum[0].m_size;
	    double posX = 100.0f + (drum[0].m_size.x * index);
	    for (unsigned int slot = 1; slot < drum.size(); slot++)
	    {
		double posY = -50.0f + (slotSize.y * slot);
		glm::vec2 slotCoords = glm::vec2(posX, posY);
		drum[slot].m_position = slotCoords; 
	    }

	}
	index++;
    }

    if (!stateNotReady)
    {
	m_timer = 10.0f;
	auto rnd = std::default_random_engine {};
	std::shuffle(m_maxVelocities.begin(), m_maxVelocities.end(), rnd);	
    }
    return stateNotReady;
   
}

StateType ActiveState::getType() const
{
    return StateType::Active;
}


void ActiveState::stop()
{
    m_timer = 0.0f;
}
