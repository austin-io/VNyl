#include "Action.hpp"

namespace vnyl {
    Action::Action(){

    }

    Action::~Action(){

    }

    void Action::onStart(){

    }

    void Action::onUpdate(){

    }

    void Action::onEnd(){
        IsFinished = true;
    }

};