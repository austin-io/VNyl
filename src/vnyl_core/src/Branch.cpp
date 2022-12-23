#include "Branch.hpp"

namespace vnyl {
    Branch::Branch(std::vector<Action*> actions, bool b)
    : ActionList(actions) {
        this->condition = b;
    }

    Branch::~Branch(){

    }

    void Branch::onStart(){

        std::cout << "Starting branch\n";
        if(!this->condition){
            QueueFinish = true;
            return;
        }

        ActionList::onStart();
    }

    void Branch::onUpdate(){
        if(!this->condition) return;

        ActionList::onUpdate();
    }

};