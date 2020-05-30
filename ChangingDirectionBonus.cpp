#include "ChangingDirectionBonus.hpp"
void ChangingDirectionBonus::Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) {
	float newAngle = -M_PI + 2 * M_PI * (float)rand() / (RAND_MAX + 1);
	ball->ChangeAngle(newAngle);
}