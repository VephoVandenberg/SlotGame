#pragma once

#include <string>

#include "Texture.h"
#include "Block.h"

namespace gameModule
{
    enum SlotType
    {
	Blue = 0,
	Purple,
	Gold,
	Red,
	Grey,
	Pink
    };
    
    class Slot : public Block
    {
	friend class ActiveState;
    public:
	Slot() = default;
	~Slot() = default;
	Slot(const Slot& slot) = default;
	Slot& operator=(const Slot& slot);

	Slot(SlotType type, glm::vec2 position, glm::vec2 size, Texture& texture, glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f));

	void changeType(SlotType type);

	inline SlotType getType() const { return m_type; } 
	
	bool operator==(Slot& slot) const;
	
    private:
	SlotType m_type;
	unsigned int m_worth;
    };
}
