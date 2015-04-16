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



typedef enum {ALL, PF, TB, GT, BA, DR} player_e;

typedef struct trigger_t {
    player_e player;
    flush_color color;
}trigger_t;




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
    
    player_e player;
    Screen screen;
    int direction;


    
};

#endif /* defined(__sjFis__Fis__) */
