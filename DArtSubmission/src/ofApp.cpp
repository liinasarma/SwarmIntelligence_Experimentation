#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    rafael.load("images/1.jpg");
    

    
    
    

for(int i = 0; i<100; i++){

    f.push_back(Fly());

}
    
    
    
    
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetBackgroundColor(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    

    for(int i = 0; i<100; i++){
        
    random1 = (int)ofRandom(100);
    random2 = (int)ofRandom(100);
        
    f.at(i).setPos(random1, random2);
        
    
    }
    
    
    
    
    
    
    for(int i = 0; i<100; i++){
    
    
    int x = f.at(i).getPosX();
    int y = f.at(i).getPosY();
        
        
        
    ofColor cur = rafael.getColor(x, y);
    int hue = getHue(cur.r,cur.g,cur.b);
        
        
        
    cout<<hue<<endl;
    }
    

    
    
    rafael.draw(0, 0);
    
    
    
    //refer to function for getting hue
    

    
    
    

    int r=255;
    int g=255;
    int b=0;
    
    
    
//    int h=getHue(r,g,b);
//    int s=getSaturation(r,g,b);
//    int br=getBrightness(r,g,b);
    
    //ofxSetColorHSB(h,s,br);
    
    
}



    int ofApp::getBrightness(float r, float g, float b) {
        return MAX(MAX(r,g),b);
    }
    
    int ofApp::getLightness(float r, float g, float b) {
        return (r + g + b) / 3.f;
    }
    
    int ofApp::getHue(float r, float g, float b) {
        float max = MAX(MAX(r, g), b);
        float min = MIN(MIN(r, g), b);
        float delta = max-min;
        if (r==max) return (0 + (g-b) / delta) * 42.5;  //yellow...magenta
        if (g==max) return (2 + (b-r) / delta) * 42.5;  //cyan...yellow
        if (b==max) return (4 + (r-g) / delta) * 42.5;  //magenta...cyan
        return 0;
    }


/*
    
    int ofApp::getSaturation(float r, float g, float b) {
        float min = MIN(MIN(r, g), b);
        float max = MAX(MAX(r, g), b);
        float delta = max-min;
        if (max!=0) return int(delta/max*255);
        return 0;
    }
    
    void ofApp:: ofxSetColorHSB(float h, float s, float b, float a) {
        a = 255;
        if (b==0) return ofSetColor(0,0,0,a); //black
        if (s==0) return ofSetColor(b,b,b,a); //gray
        
        h *= 6.0 / 255.0;
        s *= 1.0 / 255.0;
        
        float x = b * (1-s);
        float y = b * (1-s*(h-int(h)));
        float z = b * (1-s*(1-(h-int(h))));
        
        switch (int(h)) {
            case 0: return ofSetColor(b,z,x,a); //red
            case 1: return ofSetColor(y,b,x,a); //green
            case 2: return ofSetColor(x,b,z,a);
            case 3: return ofSetColor(x,y,b,a); //blue
            case 4: return ofSetColor(z,x,b,a); 
            case 5: return ofSetColor(b,x,y,a); //back to red
        }
    }

    
*/




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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