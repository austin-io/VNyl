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

        Character c = Character("John", GREEN, {ASSETS_PATH"Akari/Akari_Neutral.png"}, {"idle"});
        
        characters.push_back(&c);

        ActionList al = ActionList({//*
            new Branch(
                [](){
                    return true;
                }, {
                    new Show(&c, "idle"),
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