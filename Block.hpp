#pragma once
#include "GameObject.hpp"
#include "GameParametrs.hpp"
class Block : public GameObjectRectangle {
protected :
	int _healthPoints;
public:
	Block(sf::Vector2f& size, sf::Vector2f& position, sf::Color color);
	virtual void TakeHit() { _healthPoints--; }
	virtual int GetHealth() { return _healthPoints; }
	virtual void ChangeColor();
	virtual void ChangeScore(int& score) { score++; }
	virtual bonusType InvokeBonus() { return bonusType::NONE; };
	
};