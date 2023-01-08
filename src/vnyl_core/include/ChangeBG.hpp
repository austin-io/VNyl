#pragma once

#include "raylib.h"
#include "Action.hpp"

namespace vnyl {
    class ChangeBG : public Action {
        public:
            ChangeBG(std::string newBackground, std::string* currentBg, float* currentAlpha);
            //virtual ~ChangeBG();

            virtual void onUpdate() override;

        private:
            std::string m_NewBackground = "", *m_CurrentBackground;
            float* m_CurrentAlpha;
            bool m_FadeOut = true;
    };
};