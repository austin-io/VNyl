#include "ChangeMusic.hpp"

namespace vnyl {
    ChangeMusic::ChangeMusic(std::string newMusic, std::string* currentMusic, std::unordered_map<std::string, Music>* musicMap){
        m_NewMusic = newMusic;
        m_CurrentMusic = currentMusic;
        m_MusicMap = musicMap;
    }

    void ChangeMusic::onStart(){
        StopMusicStream((*m_MusicMap)[*m_CurrentMusic]);
        *m_CurrentMusic = m_NewMusic;
        PlayMusicStream((*m_MusicMap)[*m_CurrentMusic]);
        QueueFinish = true;
    }
};