#pragma once

#include "ActionList.hpp"
#include "Speak.hpp"
#include "Branch.hpp"
#include "Character.hpp"
#include "Show.hpp"

namespace vnyl {
    class Vnyl {
        public:
            Vnyl();
            virtual ~Vnyl();

            void run();
            void clean();
    };
};