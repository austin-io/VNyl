#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){
    
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
        SetTargetFPS(60);
        SetWindowMinSize(720, 720 / AR);

        // Render texture initialization, used to hold the rendering result so we can easily resize it
        m_RenderTarget = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
        SetTextureFilter(m_RenderTarget.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use

        m_ImageMap["campus"] = LoadTexture(ASSETS_PATH"BG/campus.png");
        m_ImageNames.push_back("campus");
        
        m_ImageMap["campus2"] = LoadTexture(ASSETS_PATH"BG/campus2.png");
        m_ImageNames.push_back("campus2");
        
        m_CurrentBackgroundImage = "campus";

        m_ImageMap["campus"].width = SCREEN_WIDTH;
        m_ImageMap["campus"].height = m_ImageMap["campus"].width * 2/3.0;

        m_ImageMap["campus2"].width = SCREEN_WIDTH;
        m_ImageMap["campus2"].height = m_ImageMap["campus2"].width * 2/3.0;
    }

    Vnyl::~Vnyl(){

        for(int i = 0; i < m_ImageNames.size(); i++){
            UnloadTexture(m_ImageMap[m_ImageNames[i]]);
        }

        CloseWindow();
    }

    void Vnyl::run(){

        std::vector<Character*> characters = std::vector<Character*>();

        Character c = Character("Alice", GREEN, 
            {ASSETS_PATH"Akari/Akari_Neutral.png",
             ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
            {"idle", "sus"});

        Character c2 = Character("Sarah", BLUE, 
            {ASSETS_PATH"Akari/Akari_Neutral.png",
             ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
            {"idle", "sus"});
        
        characters.push_back(&c);
        characters.push_back(&c2);

        int res = 0;

        ActionList al = ActionList({//*
            new Branch(
                [](){
                    return true;
                }, {
                    new ChangeBG("campus", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(&c, "idle"),
                    new Speak(&c, "Dummy text that is really long and verbose. Dummy text that is really long and verbose. Dummy text that is really long and verbose. "),
                    new Menu({"1", "2", "3", "4"}, &res),
                    //new Show(&c, "idle", true), // hide
                    new ChangeBG("campus2", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(&c2, "sus", false, Character::LEFT),
                    new Speak(&c, "Hello VNYL! This is true"),
                    new Speak(&c, "Part 2"),
                    new Speak(&c2, "Deal with it")
                }),
            new Branch(
                [](){
                    return false;
                }, {
                    new Speak(&c, "Hello VNYL! This is false")
                }),//*/
        });

        al.onStart();

        while((!al.IsFinished && !al.QueueFinish) || !WindowShouldClose()){
            if(WindowShouldClose()) break;

            float scale = std::min((float)GetScreenWidth()/RENDER_WIDTH, (float)GetScreenHeight()/RENDER_HEIGHT);

            BeginTextureMode(m_RenderTarget);
                ClearBackground(BLACK);

                //*
                DrawTexture(
                    m_ImageMap[m_CurrentBackgroundImage],
                    (RENDER_WIDTH/(float)2) - (m_ImageMap[m_CurrentBackgroundImage].width/(float)2),
                    0,
                    Fade(WHITE, m_BackgroundAlpha)
                );

                for(int i = 0; i < characters.size(); i++){
                    characters[i]->draw();
                }//*/

                al.onUpdate();

            EndTextureMode();

            BeginDrawing();

                ClearBackground(BLACK);

                // Draw render texture to screen, properly scaled
                DrawTexturePro(
                    m_RenderTarget.texture, 
                    (Rectangle){ 
                        0.0f, 0.0f, 
                        (float)m_RenderTarget.texture.width, 
                        (float)-m_RenderTarget.texture.height 
                    },
                    (Rectangle){
                        (GetScreenWidth() - ((float)RENDER_WIDTH*scale))*0.5f, 
                        (GetScreenHeight() - ((float)RENDER_HEIGHT*scale))*0.5f,
                        (float)RENDER_WIDTH*scale, 
                        (float)RENDER_HEIGHT*scale 
                    }, 
                    (Vector2){ 0, 0 }, 0.0f, WHITE);

            EndDrawing();

        }

        al.onEnd();

        al.clean();

        UnloadRenderTexture(m_RenderTarget);

    }

    void Vnyl::clean(){

    }

}