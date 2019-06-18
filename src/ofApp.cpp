#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(w/2,h/2,245));
cam.lookAt(ofVec3f(w/2,h/2,100));
//cam.lookAt(player.getPosition());
cam.orbitDeg(0,45,245,ofVec3f(0,0,0));
cam.enableOrtho();

//player.setRadius(10);
//player.setPosition(0,0);
 
cam.setParent(world.world_plane);
light.setAmbientColor(ofColor(255,255,255));
//light2.setAmbientColor(ofColor(255,255,255));
//light.setParent(world.world_plane);
light.setPosition(0,0,1000);
//light2.setPosition(128,128,1500);
world.rotateLeft();
world.setup();
}

void ofApp::update() {
//cam.lookAt(ofVec3f(w/2,h/2,0));
}

void ofApp::draw() {
ofEnableDepthTest();
cam.begin();
light.enable();
//light2.enable();
//player.draw();
world.draw();
//ofDrawBox (0,0,8,16,16,16);
cam.end();
}

void ofApp::keyPressed(int key) {
//w key
if(key == 'w') {
player.forward();
}
if(key == 's') {
}
if(key == 'a') {
//player.rotateLeft();
}
if(key == 'd') {
//player.rotateRight();
}

if(key == OF_KEY_LEFT) {
//cout << "rotate left" << endl;
world.rotateLeft();
}

if(key == OF_KEY_RIGHT) {
world.rotateRight();
}

} 

void ofApp::keyReleased(int key) {
}
