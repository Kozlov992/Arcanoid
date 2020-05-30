#pragma once
#include "Bonus.hpp"
class ShrinkageBonus : public Bonus {
public:
	ShrinkageBonus(sf::Vector2f& size, sf::Vector2f& position) : Bonus(size, position) {this->SetColor(sf::Color::Red);}
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) override;
};