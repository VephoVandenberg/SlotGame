#pragma once

#include "State.h"

namespace gameModule
{
    class IdleState : public State
    {
    public:
	IdleState() = default;
	~IdleState() = default;

	IdleState(std::array<std::deque<Slot>, 4>& slots);
	
	bool update(float dt)  override;

	StateType getType() const override;
	
    private:
	unsigned int m_drumToUpdate = 0;
	float m_timeToShow = 1.0f;
	glm::vec3 m_prevColor;
    };
}
