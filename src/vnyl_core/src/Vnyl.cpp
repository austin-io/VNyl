#include "Vnyl.hpp"

namespace vnyl {

    Vnyl::Vnyl(){
    
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VNyl Demo");
        InitAudioDevice();
        SetTargetFPS(60);
        SetWindowMinSize(720, 720 / AR);

        // Render texture initialization, used to hold the rendering result so we can easily resize it
        m_RenderTarget = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
        SetTextureFilter(m_RenderTarget.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use

        addBackground("campus", ASSETS_PATH"BG/campus.png");
        addBackground("campus2", ASSETS_PATH"BG/campus2.png");

        addMusic("main", ASSETS_PATH"Audio/BG_Main.ogg");
        addMusic("calm", ASSETS_PATH"Audio/BG_Calm.ogg");

    }

    Vnyl::~Vnyl(){

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

    }


    void Vnyl::run(){

        std::vector<Character*> characters = std::vector<Character*>();

        Character c = Character("Alice", GREEN, 
            {ASSETS_PATH"Akari/Akari_Neutral.png",
             ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
            {"idle", "sus"});

        Character c2 = Character("Sarah", BLUE, 
            {ASSETS_PATH"Akari/Akari_Neutral.png",
             ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
            {"idle", "sus"});
        
        characters.push_back(&c);
        characters.push_back(&c2);

        int res = 0;

        ActionList al = ActionList({//*
            new Branch(
                [](){
                    return true;
                }, {
                    new ChangeBG("campus", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(&c, "idle"),
                    new Speak(&c, "Dummy text that is really long and verbose. Dummy text that is really long and verbose. Dummy text that is really long and verbose. "),
                    new CodeBlock([](){
                        for(int i = 0; i < 10; i++){
                            std::cout << "CodeBlock: " << i << std::endl;
                        }
                    }),
                    new Loop(
                        [&](){
                            return res != 3;
                        },
                        [&](){
                            return std::vector<Action*>{
                                new Menu({"1", "2", "3", "4"}, &res)
                            };
                        }
                    ),
                    //new Show(&c, "idle", true), // hide
                    new ChangeMusic("calm", &m_CurrentBGM, &m_MusicMap),
                    new ChangeBG("campus2", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(&c2, "sus", false, Character::LEFT),
                    new Speak(&c, "Hello VNYL! This is true"),
                    new Speak(&c, "Part 2"),
                    new Speak(&c2, "Deal with it")
                }),
            new Branch(
                [](){
                    return false;
                }, {
                    new Speak(&c, "Hello VNYL! This is false")
                }),//*/
        });

        PlayMusicStream(m_MusicMap[m_CurrentBGM]);

        al.onStart();

        while((!al.IsFinished && !al.QueueFinish) || !WindowShouldClose()){
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

                for(int i = 0; i < characters.size(); i++){
                    characters[i]->draw();
                }//*/

                al.onUpdate();

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

        al.onEnd();

        al.clean();

        UnloadRenderTexture(m_RenderTarget);

    }

    void Vnyl::clean(){

    }

}