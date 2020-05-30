#include "BonusBlock.hpp"
/*enum class bonusType {
	ACCELERATE_BALL,
	ACCELERATE_BALL_INSTANTLY,
	ACRIVATE_SHIED,
	GLUE_BALL,
	SHRINK_CARRIAGE,
	REVERSE_BALL_DIRECTION,
};*/
bonusType BonusBlock::InvokeBonus() {
	int temp = rand() % 1200;
	if (temp < 200)
		return bonusType::ACCELERATE_BALL;
	if (temp < 400)
		return bonusType::ACCELERATE_BALL_INSTANTLY;
	if (temp < 600)
		return bonusType::ACTIVATE_SHIED;
	if (temp < 800)
		return bonusType::GLUE_BALL;
	if (temp < 1000)
		return bonusType::REVERSE_BALL_DIRECTION;
	return
		bonusType::SHRINK_CARRIAGE;
}