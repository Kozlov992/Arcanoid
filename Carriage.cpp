#include "Carriage.hpp"

Carriage::Carriage(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) : GameObjectRectangle(size, position, color) {
	_horizontalVelocity = CARRIAGE_VELOCITY;
}
void Carriage::MoveLeft() {
	sf::Vector2f position = this->getInstantPosition();
	if (position.x >= _horizontalVelocity)
		this->setPosition(sf::Vector2f(position.x - _horizontalVelocity, position.y));
	else
		this->setPosition(sf::Vector2f(0, position.y));
}
void Carriage::MoveRight(float rightEdge) {
	sf::Vector2f size = this->getSize();
	sf::Vector2f position = this->getInstantPosition();
	if (position.x + size.x + _horizontalVelocity <= rightEdge)
		this->setPosition(sf::Vector2f(position.x + _horizontalVelocity, position.y));
	else
		this->setPosition(sf::Vector2f(rightEdge - size.x, position.y));
};