#include "ActionList.hpp"

namespace vnyl {
    ActionList::ActionList(std::vector<Action*> actions){
        m_Actions = actions;
    }

    ActionList::~ActionList(){}
    
    void ActionList::onStart(){
        if(m_Actions.size() == 0){
            QueueFinish = true;
            return;
        }

        m_Actions[m_ActionIndex]->onStart();
    }

    void ActionList::onUpdate(){
        if(m_Actions.size() == 0){
            QueueFinish = true;
            return;
        }

        if(m_Actions[m_ActionIndex]->IsFinished){
            m_ActionIndex++;
            if(m_ActionIndex >= m_Actions.size()){
                QueueFinish = true;
                return;
            }
            m_Actions[m_ActionIndex]->onStart();
            return;
        }

        if(m_Actions[m_ActionIndex]->QueueFinish){
            m_Actions[m_ActionIndex]->onEnd();
            return;
        }

        m_Actions[m_ActionIndex]->onUpdate();
    }
};