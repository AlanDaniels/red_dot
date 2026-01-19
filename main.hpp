#ifndef MAIN_HPP
#define MAIN_HPP

#include "raylib.h"

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 768;
constexpr float MOVEMENT = 2.0f;


enum class GAME_MODE {
    TITLE,
    PLAYING,
    DONE
};


class RedDotGame {
public:
    RedDotGame();

    bool init();
    void drawTitleScreen();
    void drawPlayingScreen();
    void drawDoneScreen();
    void mainLoop();

    // This is a singleton. Disable copying and moving.
    RedDotGame(const RedDotGame &that) = delete;
    RedDotGame& operator=(RedDotGame const&) = delete;

private:
    GAME_MODE m_game_mode;
    bool m_mouse_clicked;
    Sound m_soundtrack;
    Vector2 m_ball_pos;
};

#endif