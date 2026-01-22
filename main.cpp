#include <cstdio>
#include <ctime>

#include "main.hpp"
#include "constants.hpp"


// Constructor.
RedDotGame::RedDotGame()
{
    m_game_mode = GAME_MODE::TITLE;
    m_is_mouse_down = false;
    m_mouse_pos = Vector2(0.0f, 0.0f);
    m_dot_collection = nullptr;
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
        m_mouse_pos = GetMousePosition();
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
    }
}


// Draw what's happening during actual gameplay.
void RedDotGame::drawPlayingScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // drawTextInCenter("Move the ball with arrow keys.");
    m_dot_collection->render();
    EndDrawing();

    if (detectLeftClick()) {
        m_game_mode = GAME_MODE::FINAL;
    }
}


// The game's all done. Show the final score.
void RedDotGame::drawFinalScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTextInCenter("All done!");
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