#pragma once

#include <cmath>
#include <vector>
#include <unordered_map>

#include "Constants.hpp"
#include "ActionList.hpp"
#include "Speak.hpp"
#include "Branch.hpp"
#include "Character.hpp"
#include "Show.hpp"
#include "ChangeBG.hpp"
#include "Menu.hpp"
#include "CodeBlock.hpp"
#include "Loop.hpp"
#include "ChangeMusic.hpp"

namespace vnyl {
    class Vnyl {
        public:
            Vnyl();
            virtual ~Vnyl();

            void run();
            void clean();

            void addBackground(std::string name, std::string filepath);
            void addMusic(std::string name, std::string filepath);
            void addSound(std::string name, std::string filepath);
        
        protected:
            RenderTexture2D m_RenderTarget;
            
            float m_BackgroundAlpha = 0;
            std::string m_CurrentBackgroundImage = "";
            std::unordered_map<std::string, Texture2D> m_ImageMap = {};
            std::vector<std::string> m_ImageNames = {};

            std::string m_CurrentBGM = "";
            std::unordered_map<std::string, Music> m_MusicMap = {};
            std::vector<std::string> m_MusicNames = {};

            std::unordered_map<std::string, Sound> m_SoundMap = {};
            std::vector<std::string> m_SoundNames = {};

            const float AR = 16/9.0;
            const int SCREEN_WIDTH  = RENDER_WIDTH;
            const int SCREEN_HEIGHT = RENDER_HEIGHT;
    };
};