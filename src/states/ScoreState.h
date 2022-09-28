#pragma once

#include <vector>

#include "State.h"

namespace gameModule
{
    class ScoreState : public State
    {
    public:
	ScoreState() = default;
	~ScoreState() = default;

	ScoreState(std::array<std::deque<Slot>, 4>& slots, unsigned int& score);	
	bool update(float dt) override;
	StateType getType() const override;

	inline bool getState() const { return m_updated; }
	inline unsigned int getScore() const { return m_score; }
	
    private:
	bool m_blink = true;
	unsigned int& m_score;
	float m_timer = 3.0f;
	std::vector<glm::vec3> m_prevColors;
    };
}
