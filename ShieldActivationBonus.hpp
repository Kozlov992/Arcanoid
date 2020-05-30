#pragma once
#include "Bonus.hpp"

class ShieldActivationBonus : public Bonus {
public:
	ShieldActivationBonus(sf::Vector2f& size, sf::Vector2f& position) :Bonus(size, position) { this->SetColor(sf::Color(114, 0, 172)); }
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) { shield->Enable(); }
};