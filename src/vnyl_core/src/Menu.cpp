#include "Menu.hpp"

namespace vnyl {
    Menu::Menu(std::vector<std::string> options, int* result){
        m_Options = options;
        m_Result = result;
    }

    void Menu::onUpdate(){
        float scale = std::min((float)GetScreenWidth()/RENDER_WIDTH, (float)GetScreenHeight()/RENDER_HEIGHT);
        
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (RENDER_WIDTH*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (RENDER_HEIGHT*scale))*0.5f)/scale;
        //virtualMouse = Vector2Clamp(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ (float)RENDER_WIDTH, (float)RENDER_HEIGHT });

        for(int i = 0; i < m_Options.size(); i++){
            float w = RENDER_WIDTH / 2;
            float h = RENDER_HEIGHT / 8;
            float x = (RENDER_WIDTH / 2.0) - (w/2);
            float p = RENDER_HEIGHT / 16;
            float maxY = ((m_Options.size()) * (h + p)) - p;
            float y = (i * (h + p)) + (RENDER_HEIGHT / 2.0) - (maxY/2);

            if(virtualMouse.x > x && virtualMouse.x < x+w && virtualMouse.y > y && virtualMouse.y < y+h){
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