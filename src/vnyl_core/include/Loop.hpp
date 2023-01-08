#pragma once

#include <functional>
#include <vector>

#include "ActionList.hpp"

namespace vnyl {
    class Loop : public ActionList {
        public:
            Loop(std::function<bool()> condition, std::function<std::vector<Action*>()> actionSpawner);
        
            virtual void onStart() override;
            virtual void onUpdate() override;

        protected:
            std::function<bool()> m_Condition;
            std::function<std::vector<Action*>()> m_ActionSpawner;
            bool condition = true;
    };
};