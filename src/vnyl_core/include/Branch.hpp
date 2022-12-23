#pragma once

#include "ActionList.hpp"

namespace vnyl {
    class Branch : public ActionList {
        public:
            Branch(std::vector<Action*> actions, bool b);
            virtual ~Branch();

            virtual void onStart() override;
            virtual void onUpdate() override;

            bool condition = false;
    };
};