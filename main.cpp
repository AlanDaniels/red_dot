#include <cstdio>

#include "raylib.h"

int main(void)
{
    constexpr int SCREEN_WIDTH = 1024;
    constexpr int SCREEN_HEIGHT = 768;
    constexpr float MOVEMENT = 2.0f;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Vector2 ballPosition = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };

    InitAudioDevice();
    Sound another = LoadSound("../Another World.mp3");
    PlaySound(another);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += MOVEMENT;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= MOVEMENT;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= MOVEMENT;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += MOVEMENT;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        DrawCircleV(ballPosition, 50, MAROON);
        EndDrawing();

        Vector2 mousePos = GetMousePosition();
        printf("Mouse Position = x: %0.f, y: %0.f\n", mousePos.x, mousePos.y);
    }

    CloseWindow();
    return 0;
}