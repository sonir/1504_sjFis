#include "slBlink.h"

slBlink::slBlink(){
    
    metro = new slMetro(1.0);
    flash = true;
    
}

void slBlink::setup(float sec){
    
    metro->set(sec);
    
}

bool slBlink::update(){
    
    if(metro->alart()){
        flash = 1-flash;
    }
    
    return flash;
    
}