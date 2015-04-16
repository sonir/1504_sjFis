#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    
    fis = new Fis(TB);
    fis->setup();
    
    //Graphic
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    //////OSC///////
    
    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        // check for mouse moved message
        if(m.getAddress() == "/fisColor"){
            // both the arguments are int32's
            trigger_t trg;
            trg.player = (player_e)m.getArgAsInt32(0);
            trg.color = (flush_color)m.getArgAsInt32(1);
            fis->setTrigger(trg);
            
        }
 
        
    }
    
    ////////////////
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, 255-BLUR);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    ofFill();
    fis->draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == ' '){
        
        ofToggleFullscreen();
        
    }else if(key == 'f'){
        
        trigger_t param;
        param.player=TB;
        param.color=WHITE;
        fis->setTrigger(param);
        
        
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
