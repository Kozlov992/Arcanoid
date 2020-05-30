#include "ShrinkageBonus.hpp"
void ShrinkageBonus::Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) {
	auto size = carriage->getSize();
	auto position = carriage->getInstantPosition();
	carriage->SetSize(sf::Vector2f(size.x - 10, size.y));
	carriage->setPosition(sf::Vector2f(position.x + 5, position.y));
}