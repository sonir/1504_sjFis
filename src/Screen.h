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
#include "ofMain.h"
#include "slBlink.h"


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
#define DELETE_AT_ONCE 1
#define SQR_COME_NUM 7
#define SQR_COME_INIT 1.0
#define SQR_COME_TARGET 0.0
#define SQR_GO_INIT 0.0
#define SQR_GO_TARGET -1.0
#define SQR_COME_SPEED 18
#define SQR_COME_COLOR_CHG_RATE 1.0
#define STEP_GRAY_MODE 3
#define BLINK_SPEED 0.3


typedef enum {WHITE, RED, YELLOW, BLUE} flush_color;

class Square {
    
    public:
    
        Square(int num, int init, int target){
            total_num = num;
            position = new float[num];
            interpolation = new Interpolation[num];
            colors = new flush_color[num];
            size_init = init;
            size_target = target;
            
            for(int i=0; i<total_num; i++){ //init squares
                //Setup standard square
                position[i] = -1;
                interpolation[i].now=init;
                colors[i]=WHITE;
            }
            
        }
    
        int total_num;
        float * position;
        int counter;
        int size_init;
        int size_target;
        flush_color * colors;
        Interpolation * interpolation;

};

class StepSquare : public Square {
    
    public:
        StepSquare(int num, int init, int target, int init2, int target2):Square(num, init, target){
            size_init2 = init2;
            size_target2 = target2;
            blink = new slBlink[num];
            
            for(int i=0; i<total_num; i++){ //init squares
                blink[i].setup(1.0/(float)(i+1)*BLINK_SPEED);
            }
        }
        void update(){
            
            for(int i=0; i<total_num;i++){
                
                interpolation[i].update();
//                ofSetColor(ofRandom(255));
//                ofRect(0.0,(interpolation[i].update()*SC_HEIGHT), SC_WIDTH, SC_HEIGHT);
            }
            
        }
    
        int size_init2;
        int size_target2;
        slBlink * blink;
    
};


class Screen {
    
public:
    
    Screen();
    void fireSquare(flush_color color);
    void fireComes(flush_color color);
    void fireGo(flush_color color);
    void drawStepSquare();

    
//    Interpolation intpComes;
    
    //Screen Managements
    int sc_width = SC_WIDTH;
    int sc_height = SC_HEIGHT;
    int sq_width = SQ_WIDTH;
    int sq_height = sc_height;
    //Square
    Square *sqr;
    StepSquare *stepSqr;
//    Square *stepSqr;
    //For Come type square
    float sq_come_init = (float)SQR_COME_INIT;
    float sq_come_target = SQR_COME_TARGET;
    float sq_go_init = (float)SQR_GO_INIT;
    float sq_go_target = SQR_GO_TARGET;

    
};

#endif /* defined(__sjFis__Screen__) */
