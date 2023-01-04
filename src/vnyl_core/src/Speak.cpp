#include "Speak.hpp"

namespace vnyl {
    Speak::Speak(Character* character, std::string s) { 
        speaker = character;
        phrase = s;
    }
    
    void Speak::onStart() {
        std::cout << speaker->name << ": " << phrase << std::endl;
        QueueFinish = true;
    }
};