#include "Character.hpp"

namespace vnyl {
    Character::Character(std::string name, Color color, std::vector<std::string> sprites, std::vector<std::string> emotions){
        themeColor = color;
        this->name = name;

        for(int i = 0; i < emotions.size(); i++){
            const std::string& key = emotions[i];
            spriteMap[key] = LoadTexture(sprites[i].c_str());
            
            float ar = spriteMap[key].width / (float)spriteMap[key].height;
            spriteMap[key].height = GetScreenHeight() * 0.9;
            spriteMap[key].width = spriteMap[key].height * ar;

            keys.push_back(key);
        }

        currentSprite = emotions[0];
    }

    Character::~Character(){
        for(int i = 0; i < keys.size(); i++){
            UnloadTexture(spriteMap[keys[i]]);
        }
    }

    void Character::draw(){
        if(isHidden) return;

        DrawTexture(
            spriteMap[currentSprite],
            (GetScreenWidth()/(float)4) - (spriteMap[currentSprite].width/(float)2),
            (GetScreenHeight() - spriteMap[currentSprite].height + 50),
            WHITE
        );
    }

    void Character::show(std::string emotion){
        isHidden = false;
        currentSprite = emotion;
    }

    void Character::hide(){
        isHidden = true;
    }
}