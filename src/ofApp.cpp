#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    gallery.loadDir("images/" + str);
    gallery.setPosition(0, ofGetWindowHeight()*0.55f);
    gallery.setSize(ofGetWindowWidth(), ofGetWindowHeight()*0.9f);

    gallery.setMode(HORIZONTAL_ALIGN);
    frameByframe = false;
    ofSetVerticalSync(true);
	ofSetFrameRate(24);

	comicMovie.loadMovie("movies/"+str+".mp4");
	vAlign = false;
	comicMovie.play();
	comicMovie.setFrame(500);
    comicMovie.setPaused(true);
    bSyncPageNeeded = false;
    bSyncClipNeeded = false;
    clipExists = false;
    onStartUp = true;

    comicFont.loadFont("fonts/verdana.ttf",42,true,true,true);
    infoImage.loadImage("images/web/"+str+"Web.png");
    filmIcon.loadImage("images/icons/filmIcon.png");


}

//--------------------------------------------------------------
void ofApp::update(){
    //ofSetWindowTitle( "4K Comics -- fps: "+ ofToString(ofGetFrameRate(), 2) );


    gallery.update();

    if(onStartUp==true){
        //put fix here.;

        onStartUp = false;
    }

    //let's see what page we're on and set the clip based on it.
    selectedPage = gallery.getSelected();
    //cout << "selectedPage = " << selectedPage << endl;
    if(selectedPage != lastSelectedPage){
        bSyncClipNeeded = true;
    }

    if(bSyncClipNeeded){
        syncClipToPage(selectedPage);
    }

    if (gallery.getMode() == 1){
        vAlign = true;
    }else{
        vAlign = false;
    }

    comicMovie.update();
    //if we're watching the movie, let's update the comic book pages.
    if(str=="wolverine"){
        if(comicMovie.getCurrentFrame() == 14001){
            bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 14801){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 15401){
           bSyncPageNeeded = true;
        }
    }else if(str=="game_of_thrones"){
         if(comicMovie.getCurrentFrame() == 5041){
            bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 6812){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 10000){
           bSyncPageNeeded = true;
        }

    }else if(str=="hamlet"){
         if(comicMovie.getCurrentFrame() == 751){
            bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 769){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 7301){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 9001){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 36841){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 39451){
           bSyncPageNeeded = true;
        }
        else if (comicMovie.getCurrentFrame() == 71401){
           bSyncPageNeeded = true;
        }

    }
    if(bSyncPageNeeded){
        syncPageToClip(comicMovie.getCurrentFrame());

    }

    if (vAlign){
        comicMovie.setPaused(false);
    }else{
        comicMovie.setPaused(true);
        }

    lastSelectedPage = selectedPage;
    debugString = "4KComics::"+ str + "::Page:" + ofToString(selectedPage);
    rect = comicFont.getStringBoundingBox(debugString, 0,0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black);
    ofSetColor(255);
	gallery.draw();



    if(vAlign){
        //draw movie area
        ofSetColor(0);
        ofRectRounded(1900,ofGetWindowHeight()*0.1f-10,comicMovie.getWidth()+20,comicMovie.getHeight()+20,20);
        ofSetColor(255);
        comicMovie.draw(1910,ofGetWindowHeight()*0.1f,comicMovie.getWidth(),comicMovie.getHeight());
        ofDrawBitmapString("frame: " + ofToString(comicMovie.getCurrentFrame()) + "/" + ofToString(comicMovie.getTotalNumFrames()) + " fps:" + ofToString(ofGetFrameRate()), 1910, ofGetWindowHeight()*0.1f-10);

        //draw info area
        ofSetColor(25);
        ofRectRounded(1910,(ofGetWindowHeight()*0.1f+comicMovie.getHeight() + 20),comicMovie.getWidth(),comicMovie.getHeight()+200,20);
        ofSetColor(255);
        infoImage.draw(1910+10,(ofGetWindowHeight()*0.1f+comicMovie.getHeight() + 30),comicMovie.getWidth()-20,comicMovie.getHeight());

    }


    //design elements and such
    ofSetColor(0);
    ofRect(0,0,ofGetWidth(),100);
    ofSetColor(255);
    comicFont.drawString(debugString,10,70);
    //ofSetColor(255);
    //ofRectRounded(10, 70, rect.width, rect.height, 20);

    if(clipExists){
        ofSetColor(0,255,0);
        ofRect(rect.width+20,18,60,60);
        ofSetColor(255);
        filmIcon.draw(rect.width+25,23,50,50);
    }else{
        ofSetColor(45);
        filmIcon.draw(rect.width+25,23,50,50);
    }
    ofSetColor(255);




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        //case ' ':
            //frameByframe=!frameByframe;
            //comicMovie.setPaused(frameByframe);
        //break;
		case 'f':
			ofToggleFullscreen();
			break;
		case 't':
			//gallery.bDebug = !gallery.bDebug;
			break;
        case 'v':
            gallery.setMode(VERTICAL_ALIGN);
            vAlign = TRUE;
            //frameByframe=!frameByframe;
            //comicMovie.setPaused(frameByframe);
            break;
        case 'h':
            gallery.setMode(HORIZONTAL_ALIGN);
            vAlign = FALSE;
            //frameByframe=!frameByframe;
            //comicMovie.setPaused(frameByframe);
            break;
        case 'e':
            //gallery.setMode(FREE);
            break;
        case 'd':
           // gallery.del( gallery.getSelected() );
        case OF_KEY_LEFT:
            gallery.moveBackward();
            break;
        case OF_KEY_RIGHT:
            gallery.moveFoward();
            break;
	}

}

//--------------------------------------------------------------
void ofApp::exit() {


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
void ofApp::windowResized(int w, int h){
       //gallery.setSize(w, h);

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo info){

}

//--------------------------------------------------------------
void ofApp::syncPageToClip(int _currentFrame){

    int currentFrame = _currentFrame;


    if (str == "wolverine"){

        if (currentFrame == 14001){
            gallery.setSelected(4);
            bSyncPageNeeded = false;
        }else if (currentFrame == 14801){
            gallery.setSelected(5);
            bSyncPageNeeded = false;
        }else if (currentFrame == 15401){
            gallery.setSelected(6);
            bSyncPageNeeded = false;
            }
    }//end wolverine
    else if (str == "game_of_thrones"){
        if (currentFrame == 5041){
            gallery.setSelected(2);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 6812){
            gallery.setSelected(4);
            bSyncPageNeeded = false;
        }
         else if (currentFrame == 10000){
            gallery.setSelected(8);
            bSyncPageNeeded = false;
        }

    }//g_o_t
    else if (str == "hamlet"){
        if (currentFrame == 751){
            gallery.setSelected(0);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 769){
            gallery.setSelected(2);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 7301){
            gallery.setSelected(7);
            bSyncPageNeeded = false;
        }
         else if (currentFrame == 9001){
            gallery.setSelected(8);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 36841){
            gallery.setSelected(15);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 39451){
            gallery.setSelected(16);
            bSyncPageNeeded = false;
        }
        else if (currentFrame == 71401){
            gallery.setSelected(25);
            bSyncPageNeeded = false;
        }

    }

}
//--------------------------------------------------------------
void ofApp::syncClipToPage(int _currentPage){

   int currentPage = _currentPage;

    if (str == "wolverine"){
        if ((currentPage == 4) && (!vAlign)){
            comicMovie.setFrame(14000);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 5) && (!vAlign)){
            comicMovie.setFrame(14800);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 6) && (!vAlign)){
            comicMovie.setFrame(15400);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else{
            clipExists = false;
            bSyncClipNeeded = false;
        }

    }//end wolverine
    else if (str == "game_of_thrones"){
        if ((currentPage == 2) && (!vAlign)){
            comicMovie.setFrame(5040);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 4) && (!vAlign)){
            comicMovie.setFrame(6811);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 8) && (!vAlign)){
            comicMovie.setFrame(9999);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else{
            clipExists = false;
            bSyncClipNeeded = false;
        }

    }//end got
    else if (str == "hamlet"){
        if ((currentPage == 0) && (!vAlign)){
            comicMovie.setFrame(750);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 2) && (!vAlign)){
            comicMovie.setFrame(768);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 7) && (!vAlign)){
            comicMovie.setFrame(7300);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 8) && (!vAlign)){
            comicMovie.setFrame(9000);
            clipExists = true;
            bSyncClipNeeded = false;
        }
         else if((currentPage == 15) && (!vAlign)){
            comicMovie.setFrame(36840);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 16) && (!vAlign)){
            comicMovie.setFrame(39450);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else if((currentPage == 25) && (!vAlign)){
            comicMovie.setFrame(71400);
            clipExists = true;
            bSyncClipNeeded = false;
        }
        else{
            clipExists = false;
            bSyncClipNeeded = false;
        }

    }//end hamlet



}
