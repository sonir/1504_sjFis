#pragma once
#define PORT 54322
#define NUM_MSG_STRINGS 20

#define FPS 120
#define BLUR 10//180 //255 is max

#include "ofMain.h"
#include "ofxOsc.h"
#include "Fis.h"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofTrueTypeFont font;
        ofxOscReceiver receiver;
        
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
    
        //Setting
          ofxXmlSettings XML;
        string xmlStructure;
        string message;

    
    
        Fis *fis;
        slBlink blink;
		
};


