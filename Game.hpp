#pragma once
#include "Ball.hpp"
#include "Block.hpp"
#include "Shield.hpp"
#include "GameObject.hpp"
#include "MovingBlock.hpp"
#include "Carriage.hpp"
#include "IndestructableBlock.hpp"
#include "Bonus.hpp"
#include "BonusBlock.hpp"
#include <vector>
#include <memory>
#include "GameParametrs.hpp"
#include "AccelerationBonus.hpp"
#include "ShieldActivationBonus.hpp"
#include "ShrinkageBonus.hpp"
#include "ChangingDirectionBonus.hpp"
#include "MovingBlockCreateBonus.hpp"
#include "GlueBonus.hpp"
class Game {
	std::vector<std::vector<std::shared_ptr<Block>>> blocks;
	std::shared_ptr<Ball> ball;
	std::shared_ptr<Shield> shield;
	std::shared_ptr<MovingBlock> movingBlock;
	std::shared_ptr<Carriage> carriage;
	std::vector<std::shared_ptr<Bonus>> currentBonuses;
	sf::Vector2f _lastCollidedBlock;
	sf::Font font;
	sf::Text ScoreBoard;
	int score = 0;
	bool _collisionnHappened;
	void RenewScore();
	void DrawTable(sf::RenderWindow& Window);
	void DrawBall(sf::RenderWindow& Window);
	void DrawBonuses(sf::RenderWindow& Window);
	void DrawShield(sf::RenderWindow& Window);
	void DrawCarriage(sf::RenderWindow& Window);
	void DrawScore(sf::RenderWindow& Window);
	void DrawMovingBlock(sf::RenderWindow& Window);
	void ProcessBonuses();
	void BonusesContact();
	void CollisionHandling();
	void CarriageContact();
	void OutOfBoundsHandling();
	void ExtractBonus();
	void ShieldContact();
	void MovingBlockContact();
public:
	Game();
	void Launch();
};