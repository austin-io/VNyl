#pragma once

#include <unordered_map>

#include "raylib.h"
#include "Action.hpp"

namespace vnyl {
    class ChangeMusic : public Action {
        public:
            ChangeMusic(std::string newMusic, std::string* currentMusic, std::unordered_map<std::string, Music>* musicMap);
        
            virtual void onStart() override;

        protected:
            std::string m_NewMusic;
            std::string* m_CurrentMusic; 
            std::unordered_map<std::string, Music>* m_MusicMap;
    };
};