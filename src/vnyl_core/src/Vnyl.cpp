#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){
        //init("VNyl Engine");
        //*m_MainActionList = ActionList(std::vector<Action*>());
    }

    Vnyl::~Vnyl(){
    }

    void Vnyl::init(std::string windowName){
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());
        InitAudioDevice();
        SetTargetFPS(60);
        SetWindowMinSize(720, 720 / AR);

        // Render texture initialization, used to hold the rendering result so we can easily resize it
        m_RenderTarget = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
        SetTextureFilter(m_RenderTarget.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use

        std::vector<Character*> m_Characters = std::vector<Character*>();
    }

    void Vnyl::addBackground(std::string name, std::string filepath){
        m_ImageMap[name] = LoadTexture(filepath.c_str());
        m_ImageNames.push_back(name);

        const float ratio = m_ImageMap[name].width / m_ImageMap[name].height;

        m_ImageMap[name].width = SCREEN_WIDTH;
        m_ImageMap[name].height = m_ImageMap[name].width / ratio;

        if(m_CurrentBackgroundImage == "")
            m_CurrentBackgroundImage = name;
    }

    void Vnyl::addMusic(std::string name, std::string filepath){
        m_MusicMap[name] = LoadMusicStream(filepath.c_str());
        m_MusicNames.push_back(name);

        if(m_CurrentBGM == "") m_CurrentBGM = name;
    }

    void Vnyl::addSound(std::string name, std::string filepath){
        m_SoundMap[name] = LoadSound(filepath.c_str());
        m_SoundNames.push_back(name);
    }

    Action* Vnyl::ClearScreen(){

        return new ActionList({
            new ScreenFade(&m_OverlayAlpha),
            //new ChangeBG("", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
            new CodeBlock([&](){
                m_CurrentBackgroundImage = "";
                m_BackgroundAlpha = 0;
                for(int i = 0; i < m_Characters.size(); i++){
                    m_Characters[i]->hide();
                }
            }),
            //new ChangeMusic("", &m_CurrentBGM, &m_MusicMap),
            new ScreenFade(&m_OverlayAlpha, true)
        });
    }

    void Vnyl::run(){

        //std::vector<Character*> characters = std::vector<Character*>();

        PlayMusicStream(m_MusicMap[m_CurrentBGM]);

        m_MainActionList->onStart();

        while((!m_MainActionList->IsFinished && !m_MainActionList->QueueFinish) || !WindowShouldClose()){
            if(WindowShouldClose()) break;

            UpdateMusicStream(m_MusicMap[m_CurrentBGM]);

            float scale = std::min((float)GetScreenWidth()/RENDER_WIDTH, (float)GetScreenHeight()/RENDER_HEIGHT);

            BeginTextureMode(m_RenderTarget);
                ClearBackground(BLACK);

                //*
                DrawTexture(
                    m_ImageMap[m_CurrentBackgroundImage],
                    (RENDER_WIDTH/(float)2) - (m_ImageMap[m_CurrentBackgroundImage].width/(float)2),
                    (RENDER_HEIGHT/(float)2) - (m_ImageMap[m_CurrentBackgroundImage].height/(float)2),
                    Fade(WHITE, m_BackgroundAlpha)
                );

                for(int i = 0; i < m_Characters.size(); i++){
                    m_Characters[i]->draw();
                }//*/

                DrawRectangle(0,0, RENDER_WIDTH, RENDER_HEIGHT, ColorAlpha(BLACK, m_OverlayAlpha));

                m_MainActionList->onUpdate();

            EndTextureMode();

            BeginDrawing();

                ClearBackground(BLACK);

                // Draw render texture to screen, properly scaled
                DrawTexturePro(
                    m_RenderTarget.texture, 
                    (Rectangle){ 
                        0.0f, 0.0f, 
                        (float)m_RenderTarget.texture.width, 
                        (float)-m_RenderTarget.texture.height 
                    },
                    (Rectangle){
                        (GetScreenWidth() - ((float)RENDER_WIDTH*scale))*0.5f, 
                        (GetScreenHeight() - ((float)RENDER_HEIGHT*scale))*0.5f,
                        (float)RENDER_WIDTH*scale, 
                        (float)RENDER_HEIGHT*scale 
                    }, 
                    (Vector2){ 0, 0 }, 0.0f, WHITE);

            EndDrawing();

        }

        m_MainActionList->onEnd();

        m_MainActionList->clean();

        UnloadRenderTexture(m_RenderTarget);

    }

    void Vnyl::clean(){
        delete m_MainActionList;

        StopSoundMulti();

        for(int i = 0; i < m_ImageNames.size(); i++){
            UnloadTexture(m_ImageMap[m_ImageNames[i]]);
        }

        for(int i = 0; i < m_MusicNames.size(); i++){
            UnloadMusicStream(m_MusicMap[m_MusicNames[i]]);
        }

        for(int i = 0; i < m_SoundNames.size(); i++){
            UnloadSound(m_SoundMap[m_SoundNames[i]]);
        }

        CloseAudioDevice();
        CloseWindow();
    }

}