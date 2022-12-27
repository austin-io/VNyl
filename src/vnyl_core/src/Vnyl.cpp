#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){}

    Vnyl::~Vnyl(){}

    void Vnyl::run(){
        
        ActionList al = ActionList({
            new Branch(
                [](){
                    return true;
                    }, {
                new Speak("Hello VNYL! This is true"),
                new Speak("Part 2"),
                new Speak("Deal with it")}),
            new Branch(
                [](){
                    return false;
                }, {
                new Speak("Hello VNYL! This is false")}),
        });

        al.onStart();

        while(!al.IsFinished && !al.QueueFinish){
            //std::cout << "21\n";
            al.onUpdate();
        }

        al.onEnd();
    }

}