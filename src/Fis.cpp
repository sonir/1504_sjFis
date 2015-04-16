//
//  Fis.cpp
//  sjFis
//
//  Created by sonir on 4/17/15.
//
//

#include "Fis.h"
using namespace std;


Fis::Fis(){
    
    
}

Fis::Fis(player_e pl){
    
    player = pl;
    
}

void Fis::setup(){
    
    //Reset sreens
    for(int i=0; i<SQR_NUM;i++){
        
            screen.sqr_position[i] = -1.0;
        }
        
    screen.sqr_counter = 0;
    
}


void Fis::setTrigger(trigger_t trg){
    
    if(trg.player==player){
        screen.fireSquare();
    }
    
    
}

void Fis::update(){
    

    
}

void Fis::draw(){
        
//    ofSetColor(255);
//    cout << screen.interpolation[0].update() << endl;
//    ofRect(screen.interpolation[0].update(), 0., SQ_WIDTH,SQ_HEIGHT);

    
    
    for(int i=0; i<SQR_NUM; i++){
        ofSetColor(255, 255, 255);
        ofRect(screen.interpolation[i].update(),0.0,SQ_WIDTH,SQ_HEIGHT);
    }
    
}