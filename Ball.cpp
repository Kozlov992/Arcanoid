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
	_velocity += 1;
	switch (numberOfTimes) {
	case 0:
		this->SetColor(sf::Color(255, 46, 18));
		break;
	case 1:
		this->SetColor(sf::Color(174, 17, 61));
		break;
	case 2:
		this->SetColor(sf::Color(176, 30, 0));
		break;
	case 3:
		this->SetColor(sf::Color(78, 0, 0));
		break;
	default:
		break;
	}
	numberOfTimes++;
}
void Ball::TakeBottomUpHit() {
	_angle = -_angle;
	//this->MoveForward();
}
void Ball::TakeSideHit() {
	_angle = M_PI - _angle;
	//this->MoveForward();
}
void Ball::TakeCarriageHit() {
	if (_angle <= -M_PI_4 && _angle >= -3 * M_PI_4) {
		_angle = -_angle;
		float delta = -M_PI / 10 + (M_PI / 5) * (float)rand() / (RAND_MAX + 1);
		_angle += delta;
		return;
	}
	if (_angle <= 0 && _angle > -M_PI_4) {
		_angle = -_angle;
		float delta = (M_PI / 5) * (float)rand() / (RAND_MAX + 1);
		_angle += delta;
		return;
	}
	if (_angle >= -M_PI && _angle < -3 * M_PI_4) {
		_angle = -_angle;
		float delta = (M_PI / 5) * (float)rand() / (RAND_MAX + 1);
		_angle -= delta;
		return;
	}
	this->TakeBottomUpHit();
}
void Ball::MoveForward() {
	sf::Vector2f delta(_velocity * cos(_angle), -_velocity * sin(_angle));
	sf::Vector2f position = this->getInstantPosition();
	this->setPosition(sf::Vector2f(position.x + delta.x, position.y + delta.y));
}
