#include <cstdio>

#include "main.hpp"


// Constructor.
RedDotGame::RedDotGame()
{
    m_game_mode = GAME_MODE::TITLE;
    m_mouse_clicked = false;
}


// Init.
bool RedDotGame::init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Click The Red Dot");
    SetTargetFPS(60);

    m_ball_pos = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };

    InitAudioDevice();
    m_soundtrack = LoadSound("../Another World.mp3");
    PlaySound(m_soundtrack);
    return true;
}


void RedDotGame::drawTitleScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Click anywhere to begin.", 10, 10, 20, DARKGRAY);
    EndDrawing();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        m_game_mode = GAME_MODE::PLAYING;
    }
}


void RedDotGame::drawPlayingScreen()
{
    if (IsKeyDown(KEY_RIGHT)) m_ball_pos.x += MOVEMENT;
    if (IsKeyDown(KEY_LEFT)) m_ball_pos.x -= MOVEMENT;
    if (IsKeyDown(KEY_UP)) m_ball_pos.y -= MOVEMENT;
    if (IsKeyDown(KEY_DOWN)) m_ball_pos.y += MOVEMENT;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Move the ball with arrow keys.", 10, 10, 20, DARKGRAY);
    DrawCircleV(m_ball_pos, 50, MAROON);
    EndDrawing();
}

void RedDotGame::drawDoneScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("All done!", 10, 10, 20, DARKGRAY);
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
        case GAME_MODE::DONE:
            drawDoneScreen();
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