#pragma once
#include "Bonus.hpp"
class MovingBonus : public Bonus {
public:
	MovingBonus(sf::Vector2f& size, sf::Vector2f& position) : Bonus(size, position) { this->SetColor(sf::Color::White); }
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) override;
};