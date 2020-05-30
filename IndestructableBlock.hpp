#pragma once
#include "Block.hpp"

class Indestructable : public Block {
public:
	Indestructable(sf::Vector2f& size, sf::Vector2f& position, sf::Color color = sf::Color::Color(46, 23, 0));
	void TakeHit() { return; };
	int GetHealth() { return 4; }
	void ChangeColor() { return; }
	void ChangeScore(int& score) { return; }
};
