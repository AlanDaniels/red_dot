#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include "raylib.h"

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 768;
constexpr int FONT_BASE_SIZE = 30;


enum class GAME_MODE {
    TITLE,
    PLAYING,
    FINAL
};


class RedDotGame {
public:
    RedDotGame();

    bool init();
    bool detectLeftClick();
    void drawTextInCenter(const std::string &text) const;

    void drawTitleScreen();
    void drawPlayingScreen();
    void drawFinalScreen();
    void mainLoop();

    // This is a singleton. Disable copying and moving.
    RedDotGame(const RedDotGame &that) = delete;
    RedDotGame& operator=(RedDotGame const&) = delete;

private:
    GAME_MODE m_game_mode;
    Sound m_soundtrack;
    Font m_default_font;
    bool m_is_mouse_down;
    Vector2 m_mouse_pos;
};

#endif