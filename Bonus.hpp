#pragma once
#include "Ball.hpp"
#include "Block.hpp"
#include "Shield.hpp"
#include "GameObject.hpp"
#include "MovingBlock.hpp"
#include "Carriage.hpp"
#include "IndestructableBlock.hpp"
#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;
#include "GameParametrs.hpp"
class Bonus : public GameObjectRectangle {
	bool _isOn = false;
public:
	void MoveDown();
	Bonus(sf::Vector2f& size, sf::Vector2f& position, sf::Color color = sf::Color::Color(255, 118, 188));
	bool IsOn() { return _isOn; };
	void Disable() { _isOn = false; }
	void Enable() { _isOn = true; }
	virtual void Activate(shared_ptr<Ball>& ball, shared_ptr<Shield>& shield, shared_ptr<MovingBlock>& movingBlock, shared_ptr<Carriage>& carriage) = 0;
	bool IsOutOfBounds(int bottomBound) { return this->getInstantPosition().y > bottomBound; }
};