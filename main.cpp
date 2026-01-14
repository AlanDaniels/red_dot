#include "raylib.h"

int main(void)
{
    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 450;
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
    }

    CloseWindow();
    return 0;
}