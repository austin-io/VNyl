#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "raylib.h"

#include "Constants.hpp"

namespace vnyl {
    class Character {
        public:
            Character(std::string name, Color color, std::vector<std::string> sprites, std::vector<std::string> emotions);
            virtual ~Character();

            void draw();
            void show(std::string emotion);
            void hide();
            bool addAlpha(float alphaDt);
            void setPosition(Vector2 newPosition);

            std::string currentSprite = "", name = "";

            static Vector2 LEFT;
            static Vector2 RIGHT;
            static Vector2 CENTER;

            Color themeColor = GREEN;

        private:
            Vector2 m_CurrentPosition = Vector2{0,0};
            bool isHidden = true;
            std::unordered_map<std::string, Texture2D> spriteMap;
            std::vector<std::string> keys;
            float m_CurrentAlpha = 0;
    };
};
