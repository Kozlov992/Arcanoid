#include "Game.hpp"
int main() {
	srand((unsigned int)time(nullptr));
	std::shared_ptr<Game> Sesion = std::make_shared<Game>();
	Sesion->Launch();
	return 0;
}