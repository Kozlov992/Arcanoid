#include "Bonus.hpp"

Bonus::Bonus(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) : GameObjectRectangle(size, position, color) { _isOn = true; }
void Bonus::MoveDown() {
	sf::Vector2f position = this->getInstantPosition();
	this->setPosition(sf::Vector2f(position.x, position.y + 3));
}