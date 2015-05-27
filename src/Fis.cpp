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
    
    if(direction==-1){
        
        for(int i =0; i<SQR_NUM;i++){
            screen.interpolation[i].now = screen.sc_width;
        }
        
    }
    
    
    //Init FillColors
    fill_color.r = 255;
    fill_color.g = 255;
    fill_color.b = 255;
    
}


void Fis::setTrigger(trigger_t trg){
    
    if(trg.player==player || trg.player==ALL){
        screen.fireSquare(trg.color);
    }
    
    
}

void Fis::setTriggerComes(trigger_t trg){
    
    if(trg.player==player || trg.player==ALL){
        screen.fireComes(trg.color);
    }
    
    
}

void Fis::setTriggerGo(trigger_t trg){
    
    if(trg.player==player || trg.player==ALL){
        screen.fireGo(trg.color);
    }
    
    
}

void Fis::resize(int w, int h){
    
    screen.sc_width = w;
    screen.sc_height = h;
    screen.sq_width = w * SQ_WIDTH_RATE;
    screen.sq_height = h;
    screen.sq_init = screen.sq_width * (-1);
    screen.sq_target = screen.sc_width;

    cout << "rezie" << endl;

    //reset all position
    for(int i =0; i<SQR_NUM;i++){
        trigger_t trg;
        trg.color = WHITE;
        trg.player = player;
        setTrigger(trg);
    }

    
}

void Fis::update(){
    

    
}

void Fis::draw(){
        
    ofSetColor(255, 255, 255);
    float foo = screen.intpComes.update();
    ofRect(0.0,(foo*screen.sc_height), screen.sc_width, screen.sc_height);
    
    
    //For Basic
    for(int i=0; i<SQR_NUM; i++){
        switch(screen.colors[i]){
            case WHITE:
            ofSetColor(255, 255, 255);
            break;

            case RED:
            ofSetColor(255, 0, 0);
            break;
            
            case YELLOW:
            ofSetColor(255, 255, 0);
            break;
            
            case BLUE:
            ofSetColor(0, 0, 255);
            break;
            
            default:
           ofSetColor(0, 255, 0);
            
        }
        
        if(direction==1){
            ofRect(screen.interpolation[i].update()*direction,0.0, screen.sq_width, screen.sq_height);
        }else if(direction==-1){
            ofRect(screen.interpolation[i].update()*direction+(screen.sq_width),0.0, screen.sq_width, screen.sq_height);
//            cout << screen.interpolation[i].update() << endl;
        }
    }
    
   
    // Fill for Lebero
    ofSetColor(fill_color.r, fill_color.g, fill_color.b, fill.update());
    ofRect(0.0 , 0.0 , ofGetWidth(),ofGetHeight());
    
}

void Fis::setFill(player_e assign, int val){
    

    if(assign==player){
    
        switch(val){
                
            case 1:
                fill_color.r = 255;
                fill_color.g = 255;
                fill_color.b = 255;
                break;
                
            case 2:
                fill_color.r = 255;
                fill_color.g = 0;
                fill_color.b = 0;
                break;
                
            case 3:
                fill_color.r = 255;
                fill_color.g = 255;
                fill_color.b = 0;
                break;
                
            case 4:
                fill_color.r = 0;
                fill_color.g = 0;
                fill_color.b = 255;
                break;
                
                
        }
        
        
        if(val>0){
            fill.init(fill.now, 255.0, DURATION_FILL_FADE);
            
        }else{
            fill.init(fill.now, 0.0, DURATION_FILL_FADE);
            
        }
    }

}
