#include "AccelerationBonus.hpp"

void AccelerationBonus::Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) {
	ball->Accelerate();
}