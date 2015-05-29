
#ifndef MYADDON
#define MYADDON
#include <iostream>
#include "slMetro.h"

class slBlink {
    
    public:
        slBlink();
        void setup(float sec);
        bool update();
    
        bool flash;
        slMetro *metro;
    
    
};

#endif