#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 1024;
constexpr int FONT_BASE_SIZE = 30;

constexpr int DOT_GRID_ROWS = 5;
constexpr int DOT_GRID_COLS = 5;

constexpr int DOT_SPACING = 175;
constexpr int DOT_GROWTH_TIME_MSECS = 10000;
constexpr int DOT_BEGIN_RADIUS = 5;
constexpr int DOT_END_RADIUS = 80;

constexpr int ROUNDS_PER_GAME = 5;
constexpr int INCR_PENALTY_TIMEOUT_MSECS = 1000;
constexpr int MAX_PENALTY_TIMEOUT_MSECS = 10000;

extern long GetCurrentTimeMsecs();

#endif
