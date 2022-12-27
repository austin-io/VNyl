#include "Action.hpp"

namespace vnyl {
    Action::Action(){

    }

    Action::~Action(){
        std::cout << "Action destroyed\n";
    }

    void Action::onStart(){

    }

    void Action::onUpdate(){

    }

    void Action::onEnd(){
        IsFinished = true;
    }

    void Action::clean(){

    }

};