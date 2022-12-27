#pragma once

#include "Action.hpp"
#include <iostream>

namespace vnyl {
    class Speak : public Action {
        public:
            Speak(std::string s){ phrase = s;}

            virtual void onStart() override {
                std::cout << phrase << std::endl;
                QueueFinish = true;
            }

            std::string phrase = "";
    };
};