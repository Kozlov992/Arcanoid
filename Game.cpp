#include "Game.hpp"
#include <ctime>
#include <string>
int Type() {
	 return rand() % 14; 
}
Game::Game() {
	sf::Vector2f blockSize(BLOCK_WIDTH, BLOCK_HEIGHT);
	sf::Vector2f carriageSize(CARRIAGE_WIDTH, CARRIAGE_HEIGHT);
	sf::Vector2f position(INITIAL_X, INITIAL_Y);
	sf::Vector2f shieldSize(SHIELD_WIDTH, SHIELD_HEIGHT);
	font.loadFromFile("Fonts/constani.ttf");
	ScoreBoard.setFont(font);
	ScoreBoard.setCharacterSize(FONT_SIZE);
	std::string title = "Score: " + std::to_string(score);
	ScoreBoard.setString(title);
	ScoreBoard.setFillColor(sf::Color::Black);
	_collisionnHappened = false;
	blocks.resize(TABLE_HEIGHT);
	shield = std::make_shared<Shield>(shieldSize, sf::Vector2f(0, WINDOW_HEIGHT - shieldSize.y - 10), sf::Color(114, 0, 172));
	ball = std::make_shared<Ball>(sf::Vector2f(528, 600), BALL_RADIUS, sf::Color(244, 179, 0));
	carriage = std::make_shared<Carriage>(carriageSize, sf::Vector2f(425, 617), sf::Color(51, 51, 255));
	movingBlock = std::make_shared<MovingBlock>(blockSize, sf::Vector2f(INITIAL_X, 350));
	sf::Vector2f delta(110, 40);
	for (int i = 0; i < TABLE_HEIGHT; i++) {
		for (int j = 0; j < TABLE_WIDTH; j++) {
			int type = Type();
			std::shared_ptr<Block> block;
			switch (type){
			case 0:
			case 1:
				block = std::make_shared<Indestructable>(blockSize, position);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				block = std::make_shared<BonusBlock>(blockSize, position, sf::Color(0, 74, 0));
				break;
			default:
				block = std::make_shared<Block>(blockSize, position, sf::Color(0, 74, 0));
				break;
			}
			blocks[i].push_back(block);
			position.x += delta.x;
		}
		position.x = 100;
		position.y += delta.y;
	}
}
void Game::DrawMovingBlock(sf::RenderWindow& Window) {
	if (movingBlock->IsOn())
		movingBlock->draw(Window);
}
void Game::DrawCarriage(sf::RenderWindow& Window) {
	carriage->draw(Window);
}

void Game::DrawBall(sf::RenderWindow& Window) {
	ball->draw(Window);
}
void Game::ProcessBonuses() {
	for (auto currentBonus : currentBonuses) {
		currentBonus->MoveDown();
		if (currentBonus->IsOutOfBounds(WINDOW_HEIGHT))
			currentBonus->Disable();
	}
}
void Game::DrawBonuses(sf::RenderWindow& Window) {
	for (auto currentBonus : currentBonuses)
		if (currentBonus->IsOn())
			currentBonus->draw(Window);
}
void Game::DrawTable(sf::RenderWindow& Window) {
	for (int i = 0; i < TABLE_HEIGHT; i++)
		for (int j = 0; j < TABLE_WIDTH; j++)
			if (blocks[i][j]->GetHealth() > 0)
				blocks[i][j]->draw(Window);
}
void Game::CollisionHandling() {
	sf::FloatRect intersection;
	bool hasIntersection = false;
	sf::FloatRect balRect = ball->getGobalBounds();
	int i, j;
	for (i = 0; i < TABLE_HEIGHT; i++) {
		for (j = 0; j < TABLE_WIDTH; j++)
			if ((blocks[i][j]->GetHealth() > 0) && blocks[i][j]->getGobalBounds().intersects(balRect, intersection)) {
				hasIntersection = true;
				break;
			}
		if (hasIntersection == true)
			break;
	}
	
	if (!hasIntersection) {
		_collisionnHappened = false;
		return;
	}
	blocks[i][j]->TakeHit();
	if (intersection.width >= intersection.height)
		ball->TakeBottomUpHit();
	else
		ball->TakeSideHit();
	blocks[i][j]->ChangeColor();
	_collisionnHappened = true;
	_lastCollidedBlock.x = i;
	_lastCollidedBlock.y = j;
	blocks[i][j]->ChangeScore(score);
}
void Game::RenewScore() {
	std::string title = "Score: " + std::to_string(score);
	ScoreBoard.setString(title);
}
void Game::CarriageContact() {
	sf::FloatRect intersection;
	sf::FloatRect ballRect = ball->getGobalBounds();
	if (carriage->getGobalBounds().intersects(ballRect, intersection)) {
		if (CARRIAGE_HEIGHT == intersection.height)
			ball->TakeSideHit();
		else
			ball->TakeCarriageHit();
	}
}
void Game::MovingBlockContact() {
	if (movingBlock->IsOn()) {
		sf::FloatRect intersection;
		bool hasIntersection = false;
		sf::FloatRect balRect = ball->getGobalBounds();
		if (movingBlock->getGobalBounds().intersects(balRect, intersection)) {
			if (intersection.width >= intersection.height)
				ball->TakeBottomUpHit();
			else
				ball->TakeSideHit();
			movingBlock->Disable();
			score++;
		}
	}
}
void Game::OutOfBoundsHandling() {
	sf::Vector2f position = ball->getInstantPosition();
	float radius = ball->getRadius();
	if (position.x <= 0 || (position.x + 2 * radius >= WINDOW_WIDTH))
		ball->TakeSideHit();
	if (position.y <= 0)
		ball->TakeBottomUpHit();
	if (position.y >= WINDOW_HEIGHT) {
		sf::Vector2f carriagePosition = carriage->getInstantPosition();
		sf::Vector2f carriageSize = carriage->getSize();
		ball->setPosition(sf::Vector2f(carriagePosition.x + carriageSize.x / 2, 600));
		ball->ChangeAngle(3 * M_PI_4);
		score--;
	}
}
void Game::BonusesContact() {
	sf::FloatRect carriageRect = carriage->getGobalBounds();
	for (auto currentBonus : currentBonuses)
		if (currentBonus->IsOn() && currentBonus->getGobalBounds().intersects(carriageRect)) {
			currentBonus->Activate(ball, shield, movingBlock, carriage);
			currentBonus->Disable();
		}
}
void Game::ShieldContact() {
	if (shield->IsOn()) {
		sf::FloatRect ballRect = ball->getGobalBounds();
		if (shield->getGobalBounds().intersects(ballRect)) {
			ball->TakeBottomUpHit();
			shield->Disable();
		}
	}
}
void Game::ExtractBonus() {
	if (blocks[_lastCollidedBlock.x][_lastCollidedBlock.y]->GetHealth() > 0)
		return;
	auto handlingBonus = blocks[_lastCollidedBlock.x][_lastCollidedBlock.y]->InvokeBonus();
	switch (handlingBonus) {
	case bonusType::NONE:
		return;
	case bonusType::ACCELERATE_BALL_INSTANTLY:
		ball->Accelerate();
		return;
	default:
		break;
	}
	sf::Vector2f pos = blocks[_lastCollidedBlock.x][_lastCollidedBlock.y]->getInstantPosition();
	sf::Vector2f size = blocks[_lastCollidedBlock.x][_lastCollidedBlock.y]->getSize();
	sf::Vector2f bonusSize(40, 40);
	sf::Vector2f bonusPos(pos.x + 30, pos.y + size.y);
	int type = Type();
	std::shared_ptr<Bonus> newBonus;
	switch (type) {
	case 1:
	case 2:
		newBonus = std::make_shared<GlueBonus>(bonusSize, bonusPos);
		break;
	case 3:
	case 4:
	case 5:
		newBonus = std::make_shared<MovingBonus>(bonusSize, bonusPos);
		break;
	case 6:
	case 7:
	case 8:
		newBonus = std::make_shared<ShieldActivationBonus>(bonusSize, bonusPos);
		break;
	case 9:
	case 10:
		newBonus = std::make_shared<ShrinkageBonus>(bonusSize, bonusPos);
		break;
	case 11:
	case 12:
		newBonus = std::make_shared<AccelerationBonus>(bonusSize, bonusPos);
		break;
	default:
		newBonus = std::make_shared<ChangingDirectionBonus>(bonusSize, bonusPos);
		break;
	}
	currentBonuses.push_back(newBonus);
}
void Game::DrawScore(sf::RenderWindow& Window) { 
	Window.draw(ScoreBoard);
}
void Game::DrawShield(sf::RenderWindow& Window) {
	if (shield->IsOn())
		shield->draw(Window);
}
void Game::Launch() {
	sf::RenderWindow Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "BREAKOUT");
	Window.setFramerateLimit(60);
	while (Window.isOpen()) {
		sf::Event ev;
		while (Window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				Window.close();
				break;
			default:
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			carriage->MoveLeft();
			if (ball->IsGlued())
				ball->PerformStickyMotion(false);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			carriage->MoveRight(WINDOW_WIDTH);
			if (ball->IsGlued())
				ball->PerformStickyMotion(true);
		}
		movingBlock->Move();
		if (!ball->IsGlued())
			ball->MoveForward();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			ball->UnGlue();
		CarriageContact();
		OutOfBoundsHandling();
		CollisionHandling();
		ShieldContact();
		BonusesContact();
		MovingBlockContact();
		if (_collisionnHappened)
			ExtractBonus();
		ProcessBonuses();
		RenewScore();
		Window.clear(sf::Color(78, 222, 159));
		DrawBonuses(Window);
		DrawCarriage(Window);
		DrawShield(Window);
		DrawTable(Window);
		DrawScore(Window);
		DrawMovingBlock(Window);
		DrawBall(Window);
		Window.display();
	}
}