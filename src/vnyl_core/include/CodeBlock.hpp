#pragma once

#include <functional>

#include "Action.hpp"

namespace vnyl {
    class CodeBlock : public Action {
        public:
            CodeBlock(std::function<void()> callback);

            virtual void onStart() override;

        protected:
            std::function<void()> m_Callback;
    };
};