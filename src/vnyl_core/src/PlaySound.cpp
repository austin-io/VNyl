#include "PlaySound.hpp"

namespace vnyl {
    PlaySound::PlaySound(Sound& sound){
        m_Sound = &sound;
    }

    void PlaySound::onStart(){
        PlaySoundMulti(*m_Sound);
        QueueFinish = true;
    }
};