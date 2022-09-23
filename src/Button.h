#pragma once

#include <glm/glm.hpp>

#include "Block.h"

namespace gameModule
{
    class Button : public Block
    {
    public:
	Button() = default;
	~Button() = default;
	
	Button(glm::vec2 position, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f));

	inline bool check() const { return m_isClicked; } 

	Button& operator=(const Button& button) = delete;
	
    private:
	bool m_isClicked = false;
    };
}
