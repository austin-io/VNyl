#include "ChangeBG.hpp"

namespace vnyl {
    ChangeBG::ChangeBG(std::string newBackground, std::string* currentBg, float* currentAlpha){
        m_NewBackground = newBackground;
        m_CurrentBackground = currentBg;
        m_CurrentAlpha = currentAlpha;
    }

    void ChangeBG::onUpdate(){
        float newAlpha = *m_CurrentAlpha;
        
        if(m_FadeOut){
            newAlpha -= GetFrameTime();
            if(newAlpha < 0){
                newAlpha = 0;
                m_FadeOut = false;
                *m_CurrentBackground = m_NewBackground;
            }
        } else {
            newAlpha += GetFrameTime();
            if(newAlpha > 1){
                newAlpha = 1;
                QueueFinish = true;
            }
        }

        *m_CurrentAlpha = newAlpha;
        
    }
};