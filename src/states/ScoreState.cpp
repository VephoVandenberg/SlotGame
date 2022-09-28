#include <iostream>

#include "ScoreState.h"

using namespace gameModule;

ScoreState::ScoreState(std::array<std::deque<Slot>, 4>& slots, unsigned int& score) :
    State(slots), m_score(score)
{
    for (auto& drum : slots)
    {
	m_prevColors.push_back(drum[m_slotToUpdate].m_color);
    }
}

bool ScoreState::update(float dt)
{
    bool firstTriple =
	m_slots[0][m_slotToUpdate] == m_slots[1][m_slotToUpdate] &&
	m_slots[0][m_slotToUpdate] == m_slots[2][m_slotToUpdate];

    /*
    std::cout << m_slots[0][m_slotToUpdate].getWorth() << " "
	      << m_slots[1][m_slotToUpdate].getWorth() << " "
	      << m_slots[2][m_slotToUpdate].getWorth() << " "
	      << m_slots[3][m_slotToUpdate].getWorth() << std::endl;
    */
    bool secondTriple =
	m_slots[1][m_slotToUpdate] == m_slots[2][m_slotToUpdate] &&
	m_slots[1][m_slotToUpdate] == m_slots[3][m_slotToUpdate];

    bool jackpot = firstTriple && secondTriple;

    glm::vec3 blinkColor = glm::vec3(0.0f, 1.0f, 0.0f);
    unsigned int index, reduce;
    if (jackpot)
    {
	index = 0;
	reduce = 0;
    }
    else if (firstTriple)
    {
	index = 0;
	reduce = 1;
    }
    else if (secondTriple)
    {
	index = 1;
	reduce = 0;
    }
    else
    {
	index = 0;
	reduce = 0;
	blinkColor = glm::vec3(1.0f, 0.0f, 0.0f);
    }

    if (m_timer > 0.0f)
    {
	for (;index < m_slots.size() - reduce; index++)
	{
	    
	    if (m_blink)
	    {
		m_slots[index][m_slotToUpdate].changeColor(blinkColor);
	    }
	    else
	    {
		m_slots[index][m_slotToUpdate].changeColor(m_prevColors[index]);
	    }
		
	}
	m_blink = !m_blink;
	m_timer -= dt;
	m_updated = false;
    }
    else
    {
	for (index = 0; index < m_slots.size(); index++)
	{
	    m_slots[index][m_slotToUpdate].changeColor(m_prevColors[index]);
	}

	if (jackpot)
	{
	    m_score += m_slots[0][m_slotToUpdate].getWorth() +
		m_slots[1][m_slotToUpdate].getWorth() +
		m_slots[2][m_slotToUpdate].getWorth() +
		m_slots[3][m_slotToUpdate].getWorth();
	}
	else if (firstTriple)
	{
	    m_score += m_slots[0][m_slotToUpdate].getWorth() +
		m_slots[1][m_slotToUpdate].getWorth() +
		m_slots[2][m_slotToUpdate].getWorth();
	}
	else if (secondTriple)
	{
	    m_score += m_slots[1][m_slotToUpdate].getWorth() +
		m_slots[2][m_slotToUpdate].getWorth() +
		m_slots[3][m_slotToUpdate].getWorth();
	}
	m_updated = true;
    }
    
    return true;
}

StateType ScoreState::getType() const
{
    return StateType::Score;
}
