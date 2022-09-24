#pragma once

#include <glm/glm.hpp>

namespace gameModule
{
    enum class EventType
    {
	CursorMoved,
	ButtonClicked,
	WindowClosed    
    };

    struct Event
    {
	virtual inline EventType getType() const = 0;
    };

    struct WindowClosedEvent : public Event
    {
	inline EventType getType() const override { return EventType::WindowClosed; }
    };
    
    struct CursorMovedEvent : public Event
    {
	glm::vec2 position;
	
	inline EventType getType() const override { return EventType::CursorMoved; } 
    };

    struct MouseButtonClickedEvent : public Event
    {
	int button;
	int action;
	int mods;

	inline EventType getType() const override { return EventType::ButtonClicked; }
    };
}
