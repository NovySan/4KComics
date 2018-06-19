#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( int argc, char *argv[]){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1920*2,1080*2, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp(argc,argv));

}
