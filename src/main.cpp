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
                
                Alice = new Character("Alice", PINK, 
                    {ASSETS_PATH"Akari/Akari_Neutral.png"}, 
                    {"idle"});

                Sarah = new Character("Sarah", BLUE, 
                    {ASSETS_PATH"Setsuko/Setsuko_Neutral.png"}, 
                    {"sus"});

                m_Characters.push_back(Alice);
                m_Characters.push_back(Sarah);

                m_MainActionList = new ActionList({
                    new ChangeBG("campus", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Show(Alice, "idle"),
                    new Speak(Alice, "Hello! And welcome to the VNyl Engine!"),
                    new Speak(Alice, "This is an example app to show you all the basic features."),
                    new Speak(Alice, "VNyl is made up of Actions that can do everything you need."),
                    new Speak(Alice, "For example: the Speak Action is what let's me talk!"),
                    new Speak(Alice, "I can also move and hide myself using the Show Action."),
                    new Show(Alice, "idle", true),
                    new Show(Alice, "idle", false, Character::RIGHT),
                    new Speak(Alice, "Pretty cool right?"),
                    new Speak(Alice, "Next up is the Menu Action."),
                    new Speak(Alice, "I can ask you a question and get an answer!"),
                    new Speak(Alice, "For example: do you like video games?"),
                    new Menu({"YES", "NO"}, &res),
                    new Branch([=](){
                        return res == 0;
                    }, {
                        new Speak(Alice, "Me too! Video games are so much fun!"),
                    }),
                    new Branch([=](){
                        return res == 1;
                    }, {
                        new Speak(Alice, "More for me then haha!"),
                    }),
                    new Speak(Alice, "Now you might be wondering: how did I know which option you picked?"),
                    new Speak(Alice, "By using a Branch Action of course! A Branch can check for any condition, and only runs if it's true!"),
                    new Speak(Alice, "Alright, next up is the Loop Action."),
                    new Speak(Alice, "This one runs over and over again until a condition is false!"),
                    new Speak(Alice, "For example: what is 2 + 2?"),
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
                    new Speak(Alice, "Correct!"),
                    new Speak(Alice, "Woah, did you hear that sound effect? I did that with the PlaySound Action!"),
                    new Speak(Alice, "I can also change the background music using, you guessed it, the ChangeMusic Action!"),
                    new ChangeMusic("calm", &m_CurrentBGM, &m_MusicMap),
                    new Speak(Alice, "Hmm, this new music needs a new background too"),
                    new Speak(Alice, "Luckily we can do that using the ChangeBG Action!"),
                    new ChangeBG("campus2", &m_CurrentBackgroundImage, &m_BackgroundAlpha),
                    new Speak(Alice, "Nice! Oh look, is that my friend Sarah?"),
                    new Show(Sarah, "sus", false, Character::LEFT),
                    new Speak(Alice, "Hey Sarah! How did the quiz go?"),
                    new Speak(Sarah, "I got an A+"),
                    new PlaySound(m_SoundMap["congratulations"]),
                    new Speak(Alice, "Congratulations! Well done!"),
                    new Speak(Alice, "What was it about?"),
                    new Speak(Sarah, "It was all about the CodeBlock Action."),
                    new Speak(Alice, "What that?"),
                    new Speak(Sarah, "It let's you run any block of code as an Action."),
                    new Speak(Alice, "Ah, that makes sense."),
                    new CodeBlock([](){
                        for(int i = 0; i < 10; i++){
                            std::cout << "CodeBlock: " << i << std::endl;
                        }
                    }),
                    new Speak(Alice, "Hmm, I think there's only one Action left?"),
                    new Speak(Sarah, "You mean the ClearScreen Action? Yeah, that erases everything and fades away."),
                    new Speak(Alice, "Perfect timing, cause that's the end!"),
                    new Speak(Alice, "Thank you for playing! Goodbye!!"),
                    new Speak(Sarah, "Later."),
                    //*
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
