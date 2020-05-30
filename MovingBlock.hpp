#pragma once
#include "GameObject.hpp"
#include "GameParametrs.hpp"
class MovingBlock : public GameObjectRectangle {
	bool _isOn;
	int _horizontalDirection;
	int _horizontalVelocity;
public:
	MovingBlock(sf::Vector2f& size, sf::Vector2f& position, sf::Color color = sf::Color::Color::White);
	bool IsOn() { return _isOn; }
	void Disable() { _isOn = false; }
	void Enable() { _isOn = true; }
	void Move();
	void SetPositiveDirection() { _horizontalDirection = 1; }
	void SetNegativeDirection() { _horizontalDirection = -1; }
};