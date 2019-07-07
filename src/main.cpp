#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1920,1080,OF_FULLSCREEN);			// <-------- setup the GL context
	ofGLWindowSettings settings;
        settings.setGLVersion(3,3);
        settings.setSize(950,950);
        ofCreateWindow(settings);
        //ofSetupOpenGL(950,950,OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
