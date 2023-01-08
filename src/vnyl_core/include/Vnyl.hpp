#pragma once

#include <cmath>

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

namespace vnyl {
    class Vnyl {
        public:
            Vnyl();
            virtual ~Vnyl();

            void run();
            void clean();
        
        protected:
            RenderTexture2D m_RenderTarget;
            std::string m_CurrentBackgroundImage = "";
            float m_BackgroundAlpha = 0;
            std::unordered_map<std::string, Texture2D> m_ImageMap = {};
            std::vector<std::string> m_ImageNames = {};

            const float AR = 16/9.0;
            const int SCREEN_WIDTH  = RENDER_WIDTH;
            const int SCREEN_HEIGHT = RENDER_HEIGHT;
    };
};