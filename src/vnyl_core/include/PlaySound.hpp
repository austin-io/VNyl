#pragma once

#include "raylib.h"

#include "Action.hpp"

namespace vnyl {
    class PlaySound : public Action {
        public:
            PlaySound(Sound& sound);

            virtual void onStart() override;

        protected:
            Sound* m_Sound;
    };
};