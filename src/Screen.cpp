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
        colors[i]=WHITE;
        
    }
        
}

void Screen::fireSquare(flush_color color){
    
    
    interpolation[sqr_counter].init(sq_init, sq_target, SQR_SPEED);
    colors[sqr_counter]=color;
    sqr_counter++;
    
    //Ring Buffer
    if(sqr_counter>=SQR_NUM)sqr_counter=0;
    
}