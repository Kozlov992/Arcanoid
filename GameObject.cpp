#include "GameObject.hpp"

GameObjectCircle::GameObjectCircle(sf::Vector2f& center, float radius, sf::Color color) {
	circle.setRadius(radius);
	circle.setPosition(center);
	circle.setFillColor(color);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(1);
}
sf::Vector2f GameObjectCircle::getInstantPosition() {
	return circle.getPosition();
}
sf::FloatRect GameObjectCircle::getGobalBounds() {
	return circle.getGlobalBounds();
}
void GameObjectCircle::setPosition(sf::Vector2f& position) {
	circle.setPosition(position);
}
void GameObjectCircle::draw(sf::RenderWindow& window) {
	window.draw(circle);
}
float GameObjectCircle::getRadius() {
	return circle.getRadius();
}
void GameObjectCircle::SetColor(sf::Color newColor) {
	circle.setFillColor(newColor);
};
void GameObjectCircle::SetRadius(float newRadius) {
	circle.setRadius(newRadius);
}

GameObjectRectangle::GameObjectRectangle(sf::Vector2f& size, sf::Vector2f& position, sf::Color color) {
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(1);
}
sf::Vector2f GameObjectRectangle::getInstantPosition() {
	return rectangle.getPosition();
}
void GameObjectRectangle::setPosition(sf::Vector2f& position) {
	rectangle.setPosition(position);
}
void GameObjectRectangle::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
}
sf::Vector2f GameObjectRectangle::getSize() {
	return rectangle.getSize();
}
sf::FloatRect GameObjectRectangle::getGobalBounds() {
	return rectangle.getGlobalBounds();
}
void GameObjectRectangle::SetColor(sf::Color newColor) {
	rectangle.setFillColor(newColor);
};
void GameObjectRectangle::SetSize(sf::Vector2f& newSize) {
	rectangle.setSize(newSize);
}