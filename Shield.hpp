#pragma once
#include "GameObject.hpp"

class Shield : public GameObjectRectangle {
	bool _isOn;
public:
	Shield(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) :GameObjectRectangle(size, position, color) { _isOn = false; }
	bool IsOn() { return _isOn; }
	void Disable() { _isOn = false; }
	void Enable() { _isOn = true; }
};
