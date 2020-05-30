#pragma once
#include "GameObject.hpp"
#include "Block.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
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
