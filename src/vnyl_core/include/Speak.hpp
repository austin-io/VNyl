#pragma once

#include "Constants.hpp"
#include "Action.hpp"
#include "Character.hpp"
#include <iostream>

namespace vnyl {
    class Speak : public Action {
        public:
            Speak(Character* character, std::string s);

            virtual void onStart() override;
            virtual void onUpdate() override;

            Character* speaker;
            std::string phrase = "";
    };
};