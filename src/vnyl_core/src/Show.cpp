#include "Show.hpp"

namespace vnyl {
    Show::Show(Character* character, std::string emotion, bool hide){
        m_Character = character;
        m_Emotion = emotion;
        m_Hide = hide;
    }

    void Show::onStart() {
        if(m_Hide)
            m_Character->hide();
        else
            m_Character->show(m_Emotion);
        
        QueueFinish = true;
    }

    void Show::onUpdate() {
    }
};