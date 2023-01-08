#include "Utils.hpp"

namespace vnyl {
    Vector2 GetVirtualMousePos(){
        float scale = std::min((float)GetScreenWidth()/RENDER_WIDTH, (float)GetScreenHeight()/RENDER_HEIGHT);

        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (RENDER_WIDTH*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (RENDER_HEIGHT*scale))*0.5f)/scale;

        return virtualMouse;
    }
};