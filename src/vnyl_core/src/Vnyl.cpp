#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){
        const float AR = 16/9.0;
        const int SCREEN_WIDTH  = 1600;
        const int SCREEN_HEIGHT = SCREEN_WIDTH / AR;

        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
        SetTargetFPS(60);

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

        Character c = Character("Sarah", GREEN, 
            {ASSETS_PATH"Akari/Akari_Neutral.png",
             ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
            {"idle", "sus"});

        Character c2 = Character("Sarah", GREEN, 
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
                    new Menu({"1", "2", "3", "4"}, &res),
                    //new Show(&c, "idle", true), // hide
                    new ChangeBG("campus2", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(&c2, "sus", false, Character::LEFT),
                    new Speak(&c, "Hello VNYL! This is true"),
                    new Speak(&c, "Part 2"),
                    new Speak(&c, "Deal with it")
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

            BeginDrawing();

            ClearBackground(BLACK);

            
            //*
            DrawTexture(
                m_ImageMap[m_CurrentBackgroundImage],
                (GetScreenWidth()/(float)2) - (m_ImageMap[m_CurrentBackgroundImage].width/(float)2),
                0,
                Fade(WHITE, m_BackgroundAlpha)
            );

            for(int i = 0; i < characters.size(); i++){
                characters[i]->draw();
            }//*/

            al.onUpdate();

            EndDrawing();

        }

        al.onEnd();

        al.clean();

    }

    void Vnyl::clean(){

    }

}