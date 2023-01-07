#include "Character.hpp"
#include "iostream"
namespace vnyl {
    Vector2 Character::LEFT   = Vector2{0,0};
    Vector2 Character::RIGHT  = Vector2{0,0};
    Vector2 Character::CENTER = Vector2{0,0};

    Character::Character(std::string name, Color color, std::vector<std::string> sprites, std::vector<std::string> emotions){
        Character::LEFT   = Vector2{GetScreenWidth()/(float)4, (float)GetScreenHeight()};
        Character::RIGHT  = Vector2{3*GetScreenWidth()/(float)4, (float)GetScreenHeight()};
        Character::CENTER = Vector2{GetScreenWidth()/(float)2, (float)GetScreenHeight()};
        
        std::cout << "Vector LEFT: " << Character::LEFT.x << ", "<< Character::LEFT.y  << std::endl;
        m_CurrentPosition = Character::CENTER;
        
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
            m_CurrentPosition.x - (spriteMap[currentSprite].width/(float)2),
            (m_CurrentPosition.y - spriteMap[currentSprite].height + 50),
            Fade(WHITE, m_CurrentAlpha)
        );
    }

    void Character::show(std::string emotion){
        isHidden = false;
        currentSprite = emotion;
    }

    void Character::hide(){
        isHidden = true;
        m_CurrentAlpha = 0;
    }

    bool Character::addAlpha(float alphaDt){
        float newAlpha = m_CurrentAlpha + alphaDt;

        if(newAlpha > 1) {
            m_CurrentAlpha = 1;
            return false;
        }

        if(newAlpha < 0) {
            m_CurrentAlpha = 0;
            return false;
        }

        m_CurrentAlpha = newAlpha;
        return true;

    }

    void Character::setPosition(Vector2 newPosition){
        m_CurrentPosition = newPosition;
    }

}