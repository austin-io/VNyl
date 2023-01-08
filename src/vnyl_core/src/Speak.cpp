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

        DrawText(speaker->name.c_str(), RENDER_WIDTH * 0.15, 10 + RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 48, speaker->themeColor);
        //DrawText(TextSubtext(phrase.c_str(), 0, (int)m_TextCounter), RENDER_WIDTH * 0.15, 64 + RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 40, WHITE);
        DrawTextBoxed(
            GetFontDefault(), 
            TextSubtext(phrase.c_str(), 0, (int)m_TextCounter), 
            (Rectangle){ 
                RENDER_WIDTH * 0.15, 
                64 + RENDER_HEIGHT - 0.3 * RENDER_HEIGHT, 
                RENDER_WIDTH - RENDER_WIDTH * 0.3, 
                0.3 * RENDER_HEIGHT - 64
            }, 40.0f, 2.0f, true, WHITE);

        m_TextCounter += GetFrameTime() * 50;

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(m_TextAnimFinished) QueueFinish = true;
            m_TextAnimFinished = true;
            m_TextCounter = phrase.size();
        }
    }
};