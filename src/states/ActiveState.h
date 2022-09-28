#pragma once

#include <vector>

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
	void stop();
	
    private:
	const float m_upPosY = -50.0f;
	const float m_downPosY = 550.0f;

	float m_timer = 10.0f;

	std::vector<float> m_maxVelocities;
	std::vector<float> m_velocities;
    };
}
