#include "Menu.hpp"

namespace vnyl {
    Menu::Menu(std::vector<std::string> options, int* result){
        m_Options = options;
        m_Result = result;
    }

    void Menu::onUpdate(){
        for(int i = 0; i < m_Options.size(); i++){
            float w = GetScreenWidth() / 2;
            float h = GetScreenHeight() / 8;
            float x = (GetScreenWidth() / 2.0) - (w/2);
            float p = GetScreenHeight() / 16;
            float maxY = ((m_Options.size()) * (h + p)) - p;
            float y = (i * (h + p)) + (GetScreenHeight() / 2.0) - (maxY/2);

            Vector2 mousePos = GetMousePosition();
            if(mousePos.x > x && mousePos.x < x+w && mousePos.y > y && mousePos.y < y+h){
                DrawRectangle(x, y, w, h, ColorAlpha(ORANGE, 0.75));
                
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    *m_Result = i;
                    QueueFinish = true;
                    return;
                }
            } else
                DrawRectangle(x, y, w, h, ColorAlpha(BLACK, 0.75));
            
            Vector2 dim = MeasureTextEx(GetFontDefault(), m_Options[i].c_str(), 48, 1);
            DrawText(m_Options[i].c_str(), x+(w/2) - dim.x/2, y+(h/2) - dim.y/2, 48, WHITE);
        }
    }
};