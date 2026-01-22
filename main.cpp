#include <cstdio>
#include <ctime>
#include <chrono>

#include "main.hpp"
#include "constants.hpp"


// Get the current time in milliseconds. Alas, Raylib doesn't provide this, only seconds.
// https://stackoverflow.com/questions/2831841/how-to-get-the-time-in-milliseconds-in-c#2834294
long GetCurrentTime()
{
    namespace sc = std::chrono;

    sc::time_point time = sc::system_clock::now();
    sc::duration since_epoch = time.time_since_epoch();
    sc::milliseconds msecs = sc::duration_cast<sc::milliseconds>(since_epoch);
    long now = msecs.count();
    return now;
}

// Constructor.
RedDotGame::RedDotGame()
{
    m_game_mode = GAME_MODE::TITLE;
    m_is_mouse_down = false;
    m_click_pos = Vector2(0.0f, 0.0f);
    m_dot_collection = nullptr;
    m_start_time = 0L;
}


// Init.
bool RedDotGame::init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Click The Red Dot");
    SetTargetFPS(60);

    InitAudioDevice();
    m_soundtrack = LoadSound("../Another World.mp3");
    PlaySound(m_soundtrack);

    unsigned int current_time = static_cast<unsigned int>(time(nullptr));
    SetRandomSeed(current_time);

    m_default_font = GetFontDefault();
    m_dot_collection = std::make_unique<DotCollection>();
    m_dot_collection->init();
    return true;
}


// Draw text in the upper left corner of the screen.
void RedDotGame::drawTextInUpperLeft(const std::string& text)
{
    DrawText(text.c_str(), 20, 20, FONT_BASE_SIZE, DARKGRAY);
}


// Draw text in the center of the screen.
void RedDotGame::drawTextInCenter(const std::string &text) const
{
    Vector2 dims = MeasureTextEx(m_default_font, text.c_str(), FONT_BASE_SIZE, 0);
    const float x = (SCREEN_WIDTH / 2) - (dims.x / 2);
    const float y = (SCREEN_HEIGHT / 2) - (dims.y / 2);
    DrawText(text.c_str(), x, y, FONT_BASE_SIZE, DARKGRAY);
}


// A mouse click only counts if it's down now, but wasn't before.
bool RedDotGame::detectLeftClick()
{
    bool pressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    if (!m_is_mouse_down && pressed) {
        m_is_mouse_down = true;
        m_click_pos = GetMousePosition();
        return true;
    } else {
        m_is_mouse_down = false;
        return false;
    }
}


// Draw the title screen.
void RedDotGame::drawTitleScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTextInCenter("Click anywhere to begin.");
    EndDrawing();

    if (detectLeftClick()) {
        m_game_mode = GAME_MODE::PLAYING;
        m_start_time = GetCurrentTime();
    }
}


// Draw what's happening during actual gameplay.
// TODO: I'd use std::format here, but that's C++ 20 only.
void RedDotGame::drawPlayingScreen()
{
    long elapsed = GetCurrentTime() - m_start_time;
    char msg[64];
    sprintf(msg, "Elapsed time = %.2f seconds", elapsed / 1000.f);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTextInUpperLeft(msg);
    m_dot_collection->render();
    EndDrawing();

    if (detectLeftClick()) {
        if (m_dot_collection->hitTest(m_click_pos)) {
            m_game_mode = GAME_MODE::FINAL;
            m_finish_time = elapsed;
        }
    }
}


// The game's all done. Show the final score.
// TODO: I'd use std::format here, but that's C++ 20 only.
void RedDotGame::drawFinalScreen() const
{
    char msg[64];
    sprintf(msg, "Congrats!\nYou finished in %.2f seconds", m_finish_time / 1000.f);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTextInCenter(msg);
    EndDrawing();
}


void RedDotGame::mainLoop()
{
    while (!WindowShouldClose()) {
        switch (m_game_mode) {
        case GAME_MODE::TITLE:
            drawTitleScreen();
            break;
        case GAME_MODE::PLAYING:
            drawPlayingScreen();
            break;
        case GAME_MODE::FINAL:
            drawFinalScreen();
            break;
        default:
            break;
        }
    }

    // All done!
    CloseWindow();
}



int main(void)
{
    RedDotGame game;
    game.init();
    game.mainLoop();
    return 0;
}