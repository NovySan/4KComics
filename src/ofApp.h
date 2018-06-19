#pragma once

#include "ofMain.h"
#include "ofxMtPhotoGallery.h"
////#include "ofxOpenCv.h"
////#include "ofxKinect.h"
////#include "ofxTuioServer.h"

class ofApp : public ofBaseApp{
	public:
	    ofApp(int argc, char *argv[])
	{
	    if(argc==2){
           str = argv[1];

	    }else{
	    str = "wolverine";
	    }
	}
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo info);
		void gotMessage(ofMessage msg);
		void syncPageToClip(int _currentFrame);
		void syncClipToPage(int _currentPage);

        ofxMtPhotoGallery   gallery;
        ofVideoPlayer 		comicMovie;
		bool                frameByframe;
		bool                vAlign;
		bool                bSyncPageNeeded;
		bool                bSyncClipNeeded;
		bool                clipExists;
		bool                onStartUp;
		string              str;
		string              debugString;
		int                 selectedPage;
		int                 lastSelectedPage;

		ofTrueTypeFont	    comicFont;
		ofImage             infoImage;
		ofImage             filmIcon;

		ofRectangle         rect;


};
