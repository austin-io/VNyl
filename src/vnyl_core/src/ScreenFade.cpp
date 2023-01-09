#include "ScreenFade.hpp"

namespace vnyl {
    ScreenFade::ScreenFade(float* currentAlpha, bool fadeIn){
        m_CurrentAlpha = currentAlpha;
        m_FadeIn = fadeIn;
    }

    void ScreenFade::onUpdate(){
        float dt = GetFrameTime() * (m_FadeIn ? -1 : 1);
        float newAlpha = *m_CurrentAlpha + dt;

        if(m_FadeIn){
            if(newAlpha < 0){
                newAlpha = 0;
                QueueFinish = true;
            }
        } else {
            if(newAlpha > 1){
                newAlpha = 1;
                QueueFinish = true;
            }
        }

        *m_CurrentAlpha = newAlpha;
    }
};