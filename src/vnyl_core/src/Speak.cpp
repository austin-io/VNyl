#include "Speak.hpp"

namespace vnyl {
    Speak::Speak(Character* character, std::string s) { 
        speaker = character;
        phrase = s;
    }
    
    void Speak::onStart() {
        //std::cout << speaker->name << ": " << phrase << std::endl;
        //QueueFinish = true;
    }

    void Speak::onUpdate(){
        DrawRectangle(
            0, RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 
            RENDER_WIDTH, 0.3 * RENDER_HEIGHT, 
            ColorAlpha(BLACK, 0.75)
        );

        DrawText(speaker->name.c_str(), RENDER_WIDTH * 0.15, 10 + RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 40, speaker->themeColor);
        DrawText(phrase.c_str(), RENDER_WIDTH * 0.15, 60 + RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 40, WHITE);

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            QueueFinish = true;
    }
};