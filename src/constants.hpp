#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// Game config.
constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 1024;
constexpr int FONT_BASE_SIZE = 30;

constexpr int DOT_GRID_ROWS = 5;
constexpr int DOT_GRID_COLS = 5;

constexpr int DOT_SPACING = 175;
constexpr int DOT_GROWTH_TIME_MSECS = 10000;
constexpr int DOT_BEGIN_RADIUS = 5;
constexpr int DOT_END_RADIUS = 80;

constexpr int ROUNDS_PER_GAME = 10;
constexpr int INCR_PENALTY_TIMEOUT_MSECS = 1000;
constexpr int MAX_PENALTY_TIMEOUT_MSECS = 10000;

// Sound resources.
constexpr const char *CLICK_SOUND_FNAME = "computer-mouse-click-351398.wav";
constexpr const char *ERROR_SOUND_FNAME = "error-08-206492.mp3";
constexpr const char *SUCCESS_SOUND_FNAME = "success-fanfare-trumpets-6185.mp3";

extern long GetCurrentTimeMsecs();

#endif
