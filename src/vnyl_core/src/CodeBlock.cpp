#include "CodeBlock.hpp"

namespace vnyl {
    CodeBlock::CodeBlock(std::function<void()> callback){
        m_Callback = callback;
    }

    void CodeBlock::onStart(){
        m_Callback();

        QueueFinish = true;
    }
};