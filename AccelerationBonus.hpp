#pragma once
#include "Bonus.hpp"
class AccelerationBonus : public Bonus {
public:
	AccelerationBonus(sf::Vector2f& size, sf::Vector2f& position): Bonus(size, position) {}
	void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) override;
};