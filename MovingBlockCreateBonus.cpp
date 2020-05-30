#include "MovingBlockCreateBonus.hpp"

void MovingBonus::Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) {
	movingBlock->setPosition(sf::Vector2f(INITIAL_X, 350));
	movingBlock->SetPositiveDirection();
	movingBlock->Enable();
}