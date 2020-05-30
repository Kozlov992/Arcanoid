#pragma once
#include "GameObject.hpp"
#include "GameParametrs.hpp"
class Carriage : public GameObjectRectangle {
	float _horizontalVelocity;
public:
	Carriage(sf::Vector2f& size, sf::Vector2f& position, sf::Color color);
	void MoveLeft();
	void MoveRight(float rightEdge);
};
