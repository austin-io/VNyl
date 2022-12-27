#include "Branch.hpp"

namespace vnyl {
    Branch::Branch(std::function<bool()> callback, std::vector<Action*> actions)
    : ActionList(actions) {
        m_Callback = callback;
    }

    Branch::~Branch(){

    }

    void Branch::onStart(){

        std::cout << "Starting branch\n";

        this->condition = m_Callback();
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