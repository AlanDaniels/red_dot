#ifndef MAIN_HPP
#define MAIN_HPP

#include <memory>
#include <string>
#include "raylib.h"
#include "dot_collection.hpp"


enum class GAME_MODE {
    TITLE,
    PLAYING,
    FINAL
};


class RedDotGame {
public:
    RedDotGame();
    ~RedDotGame() = default;

    bool init();
    bool detectLeftClick();
    static void drawTextInUpperLeft(const std::string &text);
    void drawTextInCenter(const std::string &text) const;

    void drawTitleScreen();
    void drawPlayingScreen();
    void drawFinalScreen() const;
    void mainLoop();

    // This is a singleton. Disable copying and moving.
    RedDotGame(const RedDotGame &that) = delete;
    RedDotGame(const RedDotGame &&that) = delete;
    RedDotGame& operator=(RedDotGame const &that) = delete;
    RedDotGame&& operator=(RedDotGame const &&that) = delete;

private:
    GAME_MODE m_game_mode;
    Sound m_soundtrack;
    Font m_default_font;
    bool m_is_mouse_down;
    Vector2 m_click_pos;
    long m_start_time;
    long m_finish_time;

    std::unique_ptr<DotCollection> m_dot_collection;
};

#endif