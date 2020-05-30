#pragma once
#include "Bonus.hpp"

class GlueBonus : public Bonus {
public:
	GlueBonus(sf::Vector2f& size, sf::Vector2f& position) : Bonus(size, position) { this->SetColor(sf::Color(25, 153, 0)); }
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) override;
};
