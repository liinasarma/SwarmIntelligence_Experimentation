#pragma once

#include "ofMain.h"
#include "Fly.hpp"



class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        vector< vector<int> > newTemp;
        vector<int> tempIndex;
    
    ofImage rafael;
    
    int getBrightness(float r, float g, float b);
    int getLightness(float r, float g, float b);
    int getHue(float r, float g, float b);
//    int getSaturation(float r, float g, float b);
//    void ofxSetColorHSB(float h, float s, float b, float a);
    
    int random1;
    int random2;
    
    vector<Fly> f;
};
