#include "raylib.h"

#include "Vnyl.hpp"

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

int main()
{

    vnyl::Vnyl v = vnyl::Vnyl();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH"test.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "THIS TAKES TOO LONG";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();
    return 0;
}
