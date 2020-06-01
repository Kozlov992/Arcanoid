#pragma once
#include "GameObject.hpp"
#include "Block.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
static sf::Color ACC_MODE1(255, 46, 18);
static sf::Color ACC_MODE2(174, 17, 61);
static sf::Color ACC_MODE3(176, 30, 0);
static sf::Color ACC_MODE4(78, 0, 0);
static sf::Color ACCELERATION_MODES[4] = { ACC_MODE1 , ACC_MODE2 , ACC_MODE3, ACC_MODE4 };
class Ball : public GameObjectCircle {
	double _angle;
	double _velocity;
	bool _isGlued;
public:
	Ball(sf::Vector2f& center, float radius, sf::Color color);
	void MoveForward();
	void PerformStickyMotion(bool isDirectionPositive);
	void ChangeAngle(double newAngle) { _angle = newAngle; };
	void Accelerate();
	void TakeSideHit();
	void TakeBottomUpHit();
	void TakeCarriageHit();
	bool IsGlued() { return _isGlued; }
	void Glue() { _isGlued = true; }
	void UnGlue();
};
