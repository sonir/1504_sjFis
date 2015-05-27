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
    
    //Setup cometype-square interpolation
    intpComes.now = sc_height;
    intpComes.exponential = true;
    
}

void Screen::fireSquare(flush_color color){
    
    
    interpolation[sqr_counter].init(sq_init, sq_target, SQR_SPEED);
    colors[sqr_counter]=color;
    sqr_counter++;
    
    //Ring Buffer
    if(sqr_counter>=SQR_NUM)sqr_counter=0;
    
}

void Screen::fireComes(flush_color color){
    
    intpComes.init(sq_come_init, sq_come_target, SQR_COME_SPEED);
    
}

void Screen::fireGo(flush_color color){

    intpComes.init(sq_go_init, sq_go_target, SQR_COME_SPEED);

}