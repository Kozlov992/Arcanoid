#pragma once
constexpr int TABLE_WIDTH = 8;
constexpr int TABLE_HEIGHT = 5;
constexpr float BLOCK_WIDTH = 100;
constexpr float BLOCK_HEIGHT = 32;
constexpr int WINDOW_WIDTH = 1070;
constexpr int WINDOW_HEIGHT = 700;
constexpr float BALL_RADIUS = 7;
constexpr int INITIAL_X = 100;
constexpr int INITIAL_Y = 75;
constexpr int CARRIAGE_WIDTH = 236;
constexpr int CARRIAGE_HEIGHT = 5;
constexpr int FONT_SIZE = 19;
constexpr int SHIELD_WIDTH = 1070;
constexpr int SHIELD_HEIGHT = 30;
constexpr float CARRIAGE_VELOCITY= 16;
enum class bonusType {
	ACCELERATE_BALL,
	ACCELERATE_BALL_INSTANTLY,
	ACTIVATE_SHIED,
	GLUE_BALL,
	SHRINK_CARRIAGE,
	REVERSE_BALL_DIRECTION,
	NONE,
};