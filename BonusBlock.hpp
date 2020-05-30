#pragma once
#include "Block.hpp"
class BonusBlock : public Block {
public:
	BonusBlock(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) : Block(size, position, color) {}
	bonusType InvokeBonus();
};