#pragma once

//#include <iostream>

#include "Constants.hpp"
#include "Utils.hpp"
#include "Action.hpp"
#include "Character.hpp"

namespace vnyl {
    class Speak : public Action {
        public:
            Speak(Character* character, std::string s);

            virtual void onStart() override;
            virtual void onUpdate() override;

            Character* speaker;
            std::string phrase = "";
        
        protected:
            float m_TextCounter = 0;
            bool m_TextAnimFinished = false;
    };
};