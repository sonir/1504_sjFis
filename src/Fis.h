//
//  Fis.h
//  sjFis
//
//  Created by sonir on 4/17/15.
//
//

#ifndef __sjFis__Fis__
#define __sjFis__Fis__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Screen.h"
#include "ofMain.h"

#define PLAYERS_NUM 5+1 //+1 is ALL

#define FILL_DEFAULT false
#define DURATION_FILL_FADE 6



typedef enum {ALL, PF, TB, GT, BA, DR} player_e;

typedef struct trigger_t {
    player_e player;
    flush_color color;
}trigger_t;


typedef struct {
    
    float r;
    float g;
    float b;
    
}fill_color_t;

//////////////////////////////////////

class Fis {
    
    public:
    
    Fis();
    Fis(player_e pl);

    void setup();
    void update();
    void draw();
    void setTrigger(trigger_t trg);
    void resize(int w, int h);
    void setFill(player_e assign, int val);
    
    player_e player;
    Screen screen;
    int direction;

    //Fill
    Interpolation fill;
    fill_color_t fill_color;
    
};

#endif /* defined(__sjFis__Fis__) */
