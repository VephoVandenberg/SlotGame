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
	
	Button(glm::vec2 position, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f), Texture texture = Texture());

	void click();
	void loosen();
	void checkCursorButtonCollide(const glm::vec2& position);
	
	inline bool isClicked() const { return m_isClicked; }
	inline bool checkIfTarget() const { return m_isTarget; }

	Button& operator=(const Button& button) = delete;
	
    private:
	bool m_isClicked = false;
	bool m_isTarget = false;

    private:
	void changeColorIfTarget();
    };
}
