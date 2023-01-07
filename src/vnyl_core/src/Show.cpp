#include "Show.hpp"

namespace vnyl {
    Show::Show(Character* character, std::string emotion, bool hide, Vector2 position){
        m_Character = character;
        m_Emotion = emotion;
        m_Hide = hide;
        m_ShowPosition = position;
    }

    void Show::onStart() {
        if(!m_Hide)
            m_Character->show(m_Emotion);
        m_Character->setPosition(m_ShowPosition);
    }

    void Show::onUpdate() {
        float fadeDirection = m_Hide ? -1.0f : 1.0f;
        if(!m_Character->addAlpha(fadeDirection * GetFrameTime())){
            QueueFinish = true;

            if(m_Hide)
                m_Character->hide();
        }
    }
};