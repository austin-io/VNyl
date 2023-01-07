#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){
        const float AR = 16/9.0;
        const int SCREEN_WIDTH  = 1280;
        const int SCREEN_HEIGHT = SCREEN_WIDTH / AR;

        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
        SetTargetFPS(60);
    }

    Vnyl::~Vnyl(){
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

        ActionList al = ActionList({//*
            new Branch(
                [](){
                    return true;
                }, {
                    new Show(&c, "idle"),
                    //new Show(&c, "idle", true),
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

            BeginDrawing();

            ClearBackground(BLACK);

            al.onUpdate();
            
            //*
            for(int i = 0; i < characters.size(); i++){
                characters[i]->draw();
            }//*/

            EndDrawing();

        }

        al.onEnd();

        al.clean();

    }

    void Vnyl::clean(){

    }

}