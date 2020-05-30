#pragma once
#include "Bonus.hpp"
class ChangingDirectionBonus : public Bonus {
public:
	ChangingDirectionBonus(sf::Vector2f& size, sf::Vector2f& position) : Bonus(size, position) { this->SetColor(sf::Color(0, 164, 164)); }
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) override;
};
