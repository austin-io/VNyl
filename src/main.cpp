#include "raylib.h"

#include "Vnyl.hpp"

const float AR = 16/9.0;
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = SCREEN_WIDTH / AR;

int main()
{

    vnyl::Vnyl v = vnyl::Vnyl();
    v.run();


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
    SetTargetFPS(60);

    //Texture2D texture = LoadTexture(ASSETS_PATH"test.png");

    vnyl::Character c = vnyl::Character("John", GREEN, {ASSETS_PATH"Akari/Akari_Neutral.png"}, {"idle"});
    c.show("idle");

    Texture2D bgCampusTex = LoadTexture(ASSETS_PATH"BG/campus.png");
    
    bgCampusTex.width = SCREEN_WIDTH;
    bgCampusTex.height = bgCampusTex.width * 2/3.0;

    /*
    Texture2D leftCharacterTex = LoadTexture(ASSETS_PATH"Akari/Akari_Neutral.png");
    Texture2D rightCharacterTex = LoadTexture(ASSETS_PATH"Setsuko/Setsuko_Neutral.png");

    float ar = leftCharacterTex.width / (float)leftCharacterTex.height;
    leftCharacterTex.height = SCREEN_HEIGHT * 1;
    leftCharacterTex.width = leftCharacterTex.height * ar;

    rightCharacterTex.height = SCREEN_HEIGHT * 1;
    rightCharacterTex.width = rightCharacterTex.height * ar;
    */

    //Image leftCharacterImg = LoadImage(ASSETS_PATH"Akari/Akari_Neutral.png");
    //Image rightCharacterImg = LoadImage(ASSETS_PATH"Setsuko/Setsuko_Neutral.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Background
        DrawTexture(
            bgCampusTex,
            (SCREEN_WIDTH/(float)2) - (bgCampusTex.width/(float)2),
            0,
            WHITE
            );

        c.draw();

        /*
        // Characters
        DrawTexture(
            leftCharacterTex,
            (SCREEN_WIDTH/(float)4) - (leftCharacterTex.width/(float)2),
            (SCREEN_HEIGHT - (float)leftCharacterTex.height + 50),
            WHITE
        );

        DrawTexture(
            rightCharacterTex, 
            ((3*SCREEN_WIDTH/(float)4) - (rightCharacterTex.width/(float)2)),
            (SCREEN_HEIGHT - (float)rightCharacterTex.height + 50), 
            WHITE);
        */

        DrawRectangle(0, SCREEN_HEIGHT-(SCREEN_HEIGHT*0.25), SCREEN_WIDTH, (SCREEN_HEIGHT*0.25), ColorAlpha(BLACK, 0.75));

        EndDrawing();
    }

    //UnloadTexture(texture);

    //UnloadTexture(leftCharacterTex);
    //UnloadTexture(rightCharacterTex);

    CloseWindow();
    return 0;
}
