//
//  Screen.cpp
//  sjFis
//
//  Created by sonir on 4/17/15.
//
//

#include "Screen.h"

using namespace std;

Screen::Screen(){
    
    sqr = new Square(SQR_NUM, SQR_INIT, SQR_TARGET);
    stepSqr = new StepSquare(SQR_COME_NUM, SQR_COME_INIT, SQR_COME_TARGET, SQR_GO_INIT, SQR_GO_TARGET);
    
    sqr->counter = 0;
    stepSqr->counter = 0;
}

void Screen::fireSquare(flush_color color){
    
    sqr->interpolation[sqr->counter].init(sqr->size_init, sqr->size_target, SQR_SPEED);
    sqr->colors[sqr->counter]=color;
    sqr->counter++;
    
    //Ring Buffer
    if(sqr->counter>=SQR_NUM)sqr->counter=0;
    
}

void Screen::fireComes(flush_color color){
   
    stepSqr->interpolation[stepSqr->counter].init(sq_come_init, sq_come_target, SQR_COME_SPEED);
    if(stepSqr->counter >= stepSqr->total_num) return; // IF THE SQUARE REACHED TO LIMIT DO NOTHING (JUST UPDATE LAST ONE ONLY)
    else stepSqr->counter++;
    
}

void Screen::fireGo(flush_color color){
    
    if(DELETE_AT_ONCE==1){
        
        for(int i=0; i<stepSqr->counter;i++){
            stepSqr->interpolation[i].init(sq_go_init, sq_go_target, SQR_COME_SPEED);
        }
        stepSqr->counter=0;
        
    }else{
        int counter = stepSqr->counter;
        if(counter>0){
            stepSqr->interpolation[counter-1].init(sq_go_init, sq_go_target, SQR_COME_SPEED);
            stepSqr->counter--;
        }
    }
}

void Screen::drawStepSquare(){
    stepSqr->update();
    float color_step = 1.0/(float)stepSqr->total_num;
    float step = 1.0 / STEP_GRAY_MODE;
    
    for(int i=0; i<stepSqr->total_num; i++ ){

        if(i<STEP_GRAY_MODE){ //At first draw squares in gray mode
            float stepped = (step*(float)(i+1))*SQR_COME_COLOR_CHG_RATE;
            float base = 1.0-SQR_COME_COLOR_CHG_RATE;
            int stepped_color = (int)(255.0*(base+stepped));
            ofSetColor(stepped_color);
        }else{ //After that, blink
            if(stepSqr->blink[i].update())  ofSetColor(255);
            else ofSetColor(0);
        }
        ofRect(0.0,(stepSqr->interpolation[i].now*sc_height), sc_width, sc_height);
        
    }
    
//    cout << stepSqr->counter << endl;
    
}
