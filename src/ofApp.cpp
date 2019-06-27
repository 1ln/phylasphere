#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();
//cam.setTarget(ofVec3f(0,0,0));
cam.setPosition(ofVec3f(w/2,h/2,1545));
cam.lookAt(ofVec3f(w/2,h/2,0));
//cam.setTranslationSensitivity(0,0,5);
cam.orbitDeg(0,45,1545,ofVec3f(0,0,0));
//cam.enableOrtho();
//player.setRadius(10);
//player.setPosition(0,0);
cam.setParent(world.world_plane);
//light.setAmbientColor(ofColor(255,255,255));
//light2.setAmbientColor(ofColor(255,255,255));
//light.setParent(world.world_plane);
//light.setPosition(0,0,1000);
//light2.setPosition(128,128,1500);
world.rotateLeft();
world.setup();

player.setup();
}

void ofApp::update() {
world.update();
//player.rotate(_mloc_x,_mloc_y);
//cam.lookAt(ofVec3f(w/2,h/2,0));
}

void ofApp::draw() {
ofEnableDepthTest();
//player.draw();
cam.begin();
//light.enable();
//light2.enable();
//player.draw();
world.draw();
player.draw();
//ofDrawBox (0,0,85,6,6,6);
cam.end();
}

void ofApp::keyPressed(int key) {

if(key == 'w') {
player.forward();
world.setXYOff(player.getSpeedX(),player.getSpeedY());
}
if(key == 's') {
player.back();
world.setXYOff(player.getSpeedX(),player.getSpeedY());
}
if(key == 'a') {
player.left();
world.setXYOff(player.getSpeedX(),player.getSpeedY());
}
if(key == 'd') {
player.right();
world.setXYOff(player.getSpeedX(),player.getSpeedY());
}

if(key == OF_KEY_LEFT) {
//cout << "rotate left" << endl;
world.rotateLeft();
}

if(key == OF_KEY_RIGHT) {
world.rotateRight();
}

} 

void ofApp::mouseMoved(int x,int y) {
mouse.x = x;
mouse.y = y;
}
