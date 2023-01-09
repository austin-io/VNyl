#include "raylib.h"

#include "Vnyl.hpp"

namespace vnyl {
    class MainGame : public Vnyl {
        public:
            MainGame(){
                init("Example Game");

                addBackground("campus", ASSETS_PATH"BG/campus.png");
                addBackground("campus2", ASSETS_PATH"BG/campus2.png");

                addMusic("main", ASSETS_PATH"Audio/BG_Main.ogg");
                addMusic("calm", ASSETS_PATH"Audio/BG_Calm.ogg");

                addSound("correct", ASSETS_PATH"Audio/SFX_Correct.ogg");
                addSound("congratulations", ASSETS_PATH"Audio/SFX_Congratulations.ogg");

            }

            virtual ~MainGame() {
                delete Alice;
                delete Sarah;

                clean();
            }

            Character *Alice, *Sarah;
            int res = 0;

            void setup(){
                
                Alice = new Character("Alice", GREEN, 
                    {ASSETS_PATH"Akari/Akari_Neutral.png"}, 
                    {"idle"});

                Sarah = new Character("Sarah", BLUE, 
                    {ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
                    {"sus"});

                m_Characters.push_back(Alice);
                m_Characters.push_back(Sarah);

                m_MainActionList = new ActionList({
                    new ChangeBG("campus", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    //*
                    new Branch(
                        [](){
                            return true;
                        }, {
                            new Show(Alice, "idle"),
                            new Speak(Alice, "Dummy text that is really long and verbose. Dummy text that is really long and verbose. Dummy text that is really long and verbose. "),
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
                            new PlaySound(m_SoundMap["correct"]),
                            //new Show(&c, "idle", true), // hide
                            ClearScreen(),
                            new ChangeMusic("calm", &m_CurrentBGM, &m_MusicMap),
                            new ChangeBG("campus2", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                            new Show(Alice, "idle"),
                            new Show(Sarah, "sus", false, Character::LEFT),
                            new Speak(Alice, "Hey Sarah! How did the quiz go?"),
                            new Speak(Sarah, "I got an A+"),
                            new PlaySound(m_SoundMap["congratulations"]),
                            new Speak(Alice, "Congratulations! Well done!")
                        }),
                    new Branch(
                        [](){
                            return false;
                        }, {
                            new Speak(Alice, "Hello VNYL! This is false")
                        }),
                    ClearScreen()
                    //*/
                });

            }
    };
};

int main() {
    vnyl::MainGame game = vnyl::MainGame();
    game.setup();
    game.run();
    
    return 0;
}
