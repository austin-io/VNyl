#pragma once

#include <iostream>

namespace vnyl {
    class Action {
        public:
            bool QueueFinish = false, IsFinished = false;
            
            Action();
            virtual ~Action();

            virtual void onStart();
            virtual void onUpdate();
            virtual void onEnd();
            virtual void clean();

        protected:
    };
};