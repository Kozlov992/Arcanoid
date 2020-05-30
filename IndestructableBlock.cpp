#include "IndestructableBlock.hpp"
Indestructable::Indestructable(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) : Block(size, position, color) { 
	_healthPoints = 4;
	this->SetColor(color);
}