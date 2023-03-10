#include "ActionList.hpp"

namespace vnyl {
    ActionList::ActionList(std::vector<Action*> actions){
        m_Actions = actions;
    }
    
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

        if(IsFinished || QueueFinish) return;

        if(m_Actions[m_ActionIndex]->IsFinished){
            if(m_ActionIndex + 1 >= m_Actions.size()){
                QueueFinish = true;
                return;
            }
            m_ActionIndex++;
            m_Actions[m_ActionIndex]->onStart();
            return;
        }

        if(m_Actions[m_ActionIndex]->QueueFinish){
            m_Actions[m_ActionIndex]->onEnd();
            return;
        }

        m_Actions[m_ActionIndex]->onUpdate();
    }

    void ActionList::clean(){
        for(int i = 0; i < m_Actions.size(); i++){
            m_Actions[i]->clean();
            delete m_Actions[i];
        }        
    }
};