#pragma once

#include "raylib.h"
#include "Action.hpp"

#include <vector>
#include <string>

namespace vnyl {
    class Menu : public Action {
        public:
            Menu(std::vector<std::string> options, int* result);

            virtual void onUpdate() override;

        private:
            std::vector<std::string> m_Options;
            int* m_Result;
    };
};