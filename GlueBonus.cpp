#include "GlueBonus.hpp"
void GlueBonus::Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) {
	ball->Glue();
	sf::Vector2f carriagePosition = carriage->getInstantPosition();
	sf::Vector2f carriageSize = carriage->getSize();
	ball->setPosition(sf::Vector2f(carriagePosition.x + carriageSize.x / 2, 600));
}