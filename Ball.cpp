#include "Ball.hpp"
Ball::Ball(sf::Vector2f& center, float radius, sf::Color color) :GameObjectCircle(center, radius, color) {
	_angle =  M_PI_4;
	_velocity = 6;
	_isGlued = false;
}
void Ball::UnGlue() {
	_angle = M_PI_4;
	_isGlued = false;
}
void Ball::PerformStickyMotion(bool isDirectionPositive) {
	auto position = this->getInstantPosition();
	auto radius = this->getRadius();
	if (isDirectionPositive && position.x + 2 * radius + CARRIAGE_VELOCITY <= WINDOW_WIDTH)
		this->setPosition(sf::Vector2f(position.x + CARRIAGE_VELOCITY, position.y));
	else if (!isDirectionPositive && position.x >= CARRIAGE_VELOCITY)
		this->setPosition(sf::Vector2f(position.x - CARRIAGE_VELOCITY, position.y));
}
void Ball::Accelerate() {
	static int numberOfTimes = 0;
	if (numberOfTimes > 3)
		return;
	_velocity += ACCELERATION_RATE;
	this->SetColor(ACCELERATION_MODES[numberOfTimes]);
	numberOfTimes++;
}
void Ball::TakeBottomUpHit() {
	_angle = -_angle;
}
void Ball::TakeSideHit() {
	_angle = M_PI - _angle;
}
void Ball::TakeCarriageHit() {
	if (-M_PI <= _angle && _angle <= 0) {
		float delta = (M_PI / 5) * (float)rand() / (RAND_MAX + 1);
		if (_angle <= -M_PI_4 && _angle >= -3 * M_PI_4)
			delta -= M_PI / 10;
		_angle = -_angle;
		_angle += delta;
	}
	else
		this->TakeBottomUpHit();
}
void Ball::MoveForward() {
	sf::Vector2f delta(_velocity * cos(_angle), -_velocity * sin(_angle));
	sf::Vector2f position = this->getInstantPosition();
	this->setPosition(sf::Vector2f(position.x + delta.x, position.y + delta.y));
}
