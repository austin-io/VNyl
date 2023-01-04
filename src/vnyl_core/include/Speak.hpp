#pragma once

#include "Action.hpp"
#include "Character.hpp"
#include <iostream>

namespace vnyl {
    class Speak : public Action {
        public:
            Speak(Character* character, std::string s);

            virtual void onStart() override;

            Character* speaker;
            std::string phrase = "";
    };
};