#include "ofApp.h"
//#include "ofAppGLFWWindow.h"

//--------------------------------------------------------------
int main(){
	ofAppGLFWWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	//ofSetupOpenGL(&window, 1200, 800, OF_FULLSCREEN);
    ofSetupOpenGL(&window, 1200, 800, OF_WINDOW);
	ofRunApp(new ofApp()); // start the app
}
