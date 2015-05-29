#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    //XML Setting
    if( XML.loadFile("fis_setting.xml") ){
        message = "mySettings.xml loaded!";
    }else{
        message = "unable to load mySettings.xml check data/ folder";
    }
    cout << message << endl;
    
    //Get player
    player_e player = (player_e) XML.getValue("PLAYER", (player_e)TB);
    cout << "player is " << player << endl;
    //Get Direction
    int tmp_direction = XML.getValue("DIRECTION", 1);
    cout << "direction is" << tmp_direction << endl;
    
    //Animation
    ofSetFrameRate(FPS);
    
    //Fis
    fis = new Fis(player);
    fis->direction = tmp_direction; //set the direction
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
            
        }else if(m.getAddress() == "/fill"){
            
//            fis->fill = (int) m.getArgAsInt32(0);
            player_e player = (player_e)m.getArgAsInt32(0);
            int val = m.getArgAsInt32(1);
            fis->setFill(player, val);
            
        }else if(m.getAddress() == "/fis/comes"){
            
            //stoppig sqr comes
            // both the arguments are int32's
            trigger_t trg;
            trg.player = (player_e)m.getArgAsInt32(0);
            trg.color = (flush_color)m.getArgAsInt32(1);
            fis->setTriggerComes(trg);
            
        }else if(m.getAddress() == "/fis/go"){
            
            //stoppig sqr comes
            // both the arguments are int32's
            trigger_t trg;
            trg.player = (player_e)m.getArgAsInt32(0);
            fis->setTriggerGo(trg);
            
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
        param.player=ALL;
        param.color=YELLOW;
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

    fis->resize(w,h);
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
