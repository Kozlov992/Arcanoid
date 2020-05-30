#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
class GameObjectCircle {
protected:
	sf::Color color;
	sf::CircleShape circle;
public:
	GameObjectCircle(sf::Vector2f& center, float radius, sf::Color color);
	sf::Vector2f getInstantPosition();
	void setPosition(sf::Vector2f& position);
	void draw(sf::RenderWindow& window);
	float getRadius();
	sf::FloatRect getGobalBounds();
	void SetColor(sf::Color newColor);
	void SetRadius(float newRadius);
};

class GameObjectRectangle {
protected:
	sf::Color color;
	sf::RectangleShape rectangle;
public:
	GameObjectRectangle(sf::Vector2f& size, sf::Vector2f& position, sf::Color color);
	sf::Vector2f getInstantPosition();
	void setPosition(sf::Vector2f& position);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getSize();
	sf::FloatRect getGobalBounds();
	void SetColor(sf::Color newColor);
	void SetSize(sf::Vector2f& newSize);
};