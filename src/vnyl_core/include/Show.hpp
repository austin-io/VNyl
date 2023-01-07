#pragma once

#include "Action.hpp"
#include "Character.hpp"

namespace vnyl {
    class Show : public Action {
        public:
            Show(Character* character, std::string emotion, bool hide = false, Vector2 position = Character::CENTER);

            virtual void onStart() override;
            virtual void onUpdate() override;

        protected:
            Character* m_Character;
            std::string m_Emotion;
            bool m_Hide;
            Vector2 m_ShowPosition = Vector2{0,0};
    };
};