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
#define SQ_WIDTH_RATE 0.4//0.1
#define SQ_WIDTH SC_WIDTH * SQ_WIDTH_RATE
#define SQ_HEIGHT SC_HEIGHT

//NormalType
#define SQR_NUM 8
#define SQR_INIT -1.0f * SQ_WIDTH
#define SQR_TARGET 1.0f * SC_WIDTH
#define SQR_SPEED 16
//Cometype Square
#define SQR_COME_INIT 1.0
#define SQR_COME_TARGET 0.0
#define SQR_GO_INIT 0.0
#define SQR_GO_TARGET -1.0
#define SQR_COME_SPEED 18


typedef enum {WHITE, RED, YELLOW, BLUE} flush_color;

class Screen {
    
public:
    
    Screen();
    void fireSquare(flush_color color);
    void fireComes(flush_color color);
    void fireGo(flush_color color);

    
    
    float sqr_position[SQR_NUM];
    flush_color colors[SQR_NUM];
    Interpolation interpolation[SQR_NUM];
    Interpolation intpComes;
    int sqr_counter;
    
    //Screen Managements
    int sc_width = SC_WIDTH;
    int sc_height = SC_HEIGHT;
    int sq_width = SQ_WIDTH;
    int sq_height = sc_height;
    int sq_init = SQR_INIT;
    int sq_target = SQR_TARGET;
    //For Come type square
    float sq_come_init = (float)SQR_COME_INIT;
    float sq_come_target = SQR_COME_TARGET;
    float sq_go_init = (float)SQR_GO_INIT;
    float sq_go_target = SQR_GO_TARGET;

    
};

#endif /* defined(__sjFis__Screen__) */
