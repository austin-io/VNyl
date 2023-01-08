#pragma once

#include <vector>
#include <string>

#include "raylib.h"

#include "Constants.hpp"
#include "Action.hpp"

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