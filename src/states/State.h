#pragma once

#include <array>
#include <deque>

#include "../Slot.h"

namespace gameModule
{
    enum class StateType
    {
	Idle,
	Active,
	Score    
    };
    
    class State
    {
    public:
	State() = default;
	virtual ~State() = default;

	State(std::array<std::deque<Slot>, 4>& slots);
	
	virtual bool update(float dt = 0.0f) = 0;
	virtual StateType getType() const = 0;

	inline bool getStatus() const { return m_updated; }

    protected:
	std::array<std::deque<Slot>, 4>& m_slots;
	const unsigned int m_slotToUpdate = 3;
	bool m_updated = false;
    };
}
