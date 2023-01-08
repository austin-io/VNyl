#pragma once

#include "ActionList.hpp"
#include "Speak.hpp"
#include "Branch.hpp"
#include "Character.hpp"
#include "Show.hpp"
#include "ChangeBG.hpp"
#include "Menu.hpp"

namespace vnyl {
    class Vnyl {
        public:
            Vnyl();
            virtual ~Vnyl();

            void run();
            void clean();
        
        protected:
            std::string m_CurrentBackgroundImage = "";
            float m_BackgroundAlpha = 0;
            std::unordered_map<std::string, Texture2D> m_ImageMap = {};
            std::vector<std::string> m_ImageNames = {};
    };
};