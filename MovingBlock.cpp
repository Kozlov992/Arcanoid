#include "MovingBlock.hpp"
MovingBlock::MovingBlock(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) :GameObjectRectangle(size, position, color) { 
	_isOn = false;
	_horizontalDirection = 1;
	_horizontalVelocity = 3;
};

void MovingBlock::Move() {
	auto position = this->getInstantPosition();
	auto size = this->getSize();
	if (_horizontalDirection == -1 && position.x < 0)
		this->SetPositiveDirection();
	if (_horizontalDirection == 1 && position.x + size.x > WINDOW_WIDTH)
		this->SetNegativeDirection();
	this->setPosition(sf::Vector2f(position.x + _horizontalDirection * _horizontalVelocity, position.y));
}