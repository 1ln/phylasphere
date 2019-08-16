#include "ofApp.h"

void ofApp::setup() {

//_w = ofGetWidth();
//_h = ofGetHeight();

_draw_sys_info = false;
_draw_sys_count = 0;
font.load("arial.ttf",10);


//_r = 1000000;   
//_r = ofRandom(0,4000000);   
//_r2 = ofRandom(0,_r);

ofBackground(0);

ofSeedRandom();

cam.setPosition(ofVec3f(250,250,250));
cam.lookAt(ofVec3f(0,0,0));

cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_LEFT);
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_TRANSLATE_Z,OF_MOUSE_BUTTON_RIGHT);
cam.addInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_RIGHT);

star.setup();
planet.setup();
//ofSetGlobalAmbientColor(ofColor(0,0,0));

}

void ofApp::system_info() {

string fps = "FPS: " + ofToString(ofGetFrameRate(),2);
font.drawString(fps,15,15);

} 

void ofApp::keyPressed(int key) {

    if(key == 'i') {
    _draw_sys_info = true;
    ++_draw_sys_count;
    }
    if(_draw_sys_count > 1) {
    _draw_sys_info = false;
    _draw_sys_count = 0;

    }

    if(key == 'r') {
    
    }

}

void ofApp::keyReleased(int key) {

    if(key == 'i' && _draw_sys_count > 0) {
    }

    if(key == 'r') {
    }
} 

void ofApp::mouseMoved(int x,int y) {

mouse.x = _x;
mouse.y = _y;

}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST);
ofEnableLighting();
ofSetSmoothLighting(true);
//cam.begin();

if(_draw_sys_info == true) {
//system_info();

ofTranslate(planet.g_Position());
cam.setTarget(planet.g_Position());
cam.lookAt(planet.g_Position());
cam.begin();
} else {
cam.setTarget(ofVec3f(0,0,0));
cam.lookAt(ofVec3f(0,0,0));
cam.begin();
}
//cam.begin();

star.draw();
planet.draw();

//mat.end();
cam.end();
//ofDisableLighting();
}

void ofApp::update() {

w_mouse = cam.screenToWorld(ofVec3f(mouse.x,mouse.y,0.0f));
w_mouse_end = cam.screenToWorld(ofVec3f(mouse.x,mouse.y,1.0f)); 
//mouse_ray.s = w_mouse;
//mouse_ray.t = w_mouse_end;

star.update();
planet.update();
}
