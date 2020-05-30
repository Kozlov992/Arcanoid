#include "Block.hpp"
Block::Block(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) : GameObjectRectangle(size, position, color) {
	_healthPoints = 1 + rand() % 3;
	if (_healthPoints != 3)
		this->ChangeColor();
}
void Block::ChangeColor() {
	switch (_healthPoints) {
	case 2:
		this->SetColor(sf::Color(229, 108, 25));
		break;
	case 1:
		this->SetColor(sf::Color(184, 27, 27));
	default:
		break;
	}
}