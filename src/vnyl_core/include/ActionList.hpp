#pragma once

#include "Action.hpp"
#include <vector>

namespace vnyl {
    class ActionList : public Action {
        public:
            ActionList(std::vector<Action*> actions);

            virtual void onStart() override;
            virtual void onUpdate() override;
            virtual void clean() override;
        
        protected:
            std::vector<Action*> m_Actions;
            int m_ActionIndex = 0;
    };
};