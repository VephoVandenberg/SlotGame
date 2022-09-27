#pragma once

#include "State.h"

namespace gameModule
{
    class ActiveState : public State
    {
    public:
	ActiveState() = default;
	~ActiveState() = default;

	ActiveState(std::array<std::deque<Slot>, 4>& slots);

	bool update(float dt) override;
	StateType getType() const override;
	
    private:
	const float m_upPosY = -50.0f;
	const float m_downPosY = 550.0f;

	float m_timer = 5.0f;
	float m_velocity = 2.0f;
    };
}
