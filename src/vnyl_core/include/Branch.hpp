#pragma once

#include "ActionList.hpp"
#include <functional>

namespace vnyl {
    class Branch : public ActionList {
        public:
            Branch(std::function<bool()> callback, std::vector<Action*> actions);
            virtual ~Branch();

            virtual void onStart() override;
            virtual void onUpdate() override;

            bool condition = false;
        protected:
            std::function<bool()> m_Callback;
    };
};