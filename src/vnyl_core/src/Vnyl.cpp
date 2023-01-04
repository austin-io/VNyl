#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){}

    Vnyl::~Vnyl(){}

    void Vnyl::run(){
        
        Character c = Character("John", GREEN, {ASSETS_PATH"Akari/Akari_Neutral.png"}, {"idle"});

        ActionList al = ActionList({
            new Branch(
                [](){
                    return true;
                }, {
                    new Speak(&c, "Hello VNYL! This is true"),
                    new Speak(&c, "Part 2"),
                    new Speak(&c, "Deal with it")
                }),
            new Branch(
                [](){
                    return false;
                }, {
                    new Speak(&c, "Hello VNYL! This is false")
                }),
        });

        al.onStart();

        while(!al.IsFinished && !al.QueueFinish){
            //std::cout << "21\n";
            al.onUpdate();
        }

        al.onEnd();

        al.clean();
    }

    void Vnyl::clean(){

    }

}