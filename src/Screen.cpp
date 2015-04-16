//
//  Screen.cpp
//  sjFis
//
//  Created by sonir on 4/17/15.
//
//

#include "Screen.h"

Screen::Screen(){
    
    sqr_counter = 0;
    for(int i=0; i<SQR_NUM; i++){
        sqr_position[i] = -1;
        interpolation[i].now=SQR_INIT;
    }
        
}

void Screen::fireSquare(){
    
    
    interpolation[sqr_counter].init(SQR_INIT, SQR_TARGET, SQR_SPEED);
    sqr_counter++;
    
    //Ring Buffer
    if(sqr_counter>=SQR_NUM)sqr_counter=0;
    
}