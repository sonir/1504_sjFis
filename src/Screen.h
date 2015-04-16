//
//  Screen.h
//  sjFis
//
//  Created by sonir on 4/17/15.
//
//

#ifndef __sjFis__Screen__
#define __sjFis__Screen__

#include <stdio.h>
#include "slInterpolation.h"

#define SC_WIDTH 1024
#define SC_HEIGHT 764
#define SQ_WIDTH 800
#define SQ_HEIGHT SC_HEIGHT

#define SQR_NUM 8
#define SQR_INIT -1.0f * SQ_WIDTH
#define SQR_TARGET 1.0f * SC_WIDTH
#define SQR_SPEED 15

class Screen {
    
public:
    
    Screen();
    void fireSquare();
    
    float sqr_position[SQR_NUM];
    Interpolation interpolation[SQR_NUM];
    int sqr_counter;
    
};

#endif /* defined(__sjFis__Screen__) */
