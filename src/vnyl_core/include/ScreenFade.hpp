#pragma once

#include "raylib.h"

#include "Action.hpp"

namespace vnyl {
    class ScreenFade : public Action {
        public:
            ScreenFade(float* currentAlpha, bool fadeIn = false);

            virtual void onUpdate() override;
        
        protected:
            float* m_CurrentAlpha;
            bool m_FadeIn = false;
    };
};