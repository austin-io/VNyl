#include "Loop.hpp"

namespace vnyl {
    Loop::Loop(std::function<bool()> condition, std::function<std::vector<Action*>()> actionSpawner)
    : ActionList(actionSpawner()) {
        m_Condition = condition;
        m_ActionSpawner = actionSpawner;
    }

    void Loop::onStart(){

        std::cout << "Starting branch\n";

        this->condition = m_Condition();
        if(!this->condition){
            QueueFinish = true;
            return;
        }

        ActionList::onStart();
    }

    void Loop::onUpdate(){
        if(!this->condition) return;

        ActionList::onUpdate();

        if(QueueFinish){
            this->condition = m_Condition();
            if(this->condition){
                QueueFinish = false;
                clean();
                m_ActionIndex = 0;
                m_Actions = m_ActionSpawner();
                ActionList::onStart();
            }
        }
    }
};