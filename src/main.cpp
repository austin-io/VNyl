#include "raylib.h"

#include "Vnyl.hpp"

const float AR = 16/9.0;
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = SCREEN_WIDTH / AR;

int main()
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
    SetTargetFPS(60);

    vnyl::Vnyl v = vnyl::Vnyl();
    v.run();
    
    //vnyl::Character c = vnyl::Character("John", GREEN, {ASSETS_PATH"Akari/Akari_Neutral.png"}, {"idle"});
    //c.show("idle");

    Texture2D bgCampusTex = LoadTexture(ASSETS_PATH"BG/campus.png");
    
    bgCampusTex.width = SCREEN_WIDTH;
    bgCampusTex.height = bgCampusTex.width * 2/3.0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Background
        DrawTexture(
            bgCampusTex,
            (SCREEN_WIDTH/(float)2) - (bgCampusTex.width/(float)2),
            0,
            Fade(WHITE, 0.75)
            );

        //c.draw();

        DrawRectangle(0, SCREEN_HEIGHT-(SCREEN_HEIGHT*0.25), SCREEN_WIDTH, (SCREEN_HEIGHT*0.25), ColorAlpha(BLACK, 0.75));

        EndDrawing();
    }

    UnloadTexture(bgCampusTex);

    CloseWindow();
    return 0;
}
