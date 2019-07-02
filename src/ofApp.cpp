#include "ofApp.h"

void ofApp::setup() {

ofBackground(0);
w = ofGetWidth();
h = ofGetHeight();
cam.setPosition(ofVec3f(w/2,h/2,1545));
cam.lookAt(ofVec3f(w/2,h/2,0));
cam.orbitDeg(0,45,1000,ofVec3f(0,0,0));
//cam.enableOrtho();
cam.setParent(world.world_plane);
//light.setAmbientColor(ofColor(255,255,255));
world.rotate45();
world.setup();

player.setup();
}

void ofApp::update() {
world.update();
//player.forward();
//world.offXY(player.speedX(),player.speedY());

//player.mouseFromWorld(cam.screenToWorld(mouse));
}

void ofApp::draw() {
ofEnableDepthTest();
cam.begin();
//light.enable();
world.draw();
player.draw();
//ofDrawBox (0,0,85,6,6,6);
cam.end();
}

void ofApp::keyPressed(int key) {

if(key == 'w') {
player.forward();
world.offXY(player.speedX(),player.speedY());
}

/*
if(key == 's') {
player.back();
world.offXY(player.speedX(),player.speedY());
}
if(key == 'a') {
player.left();
world.offXY(player.speedX(),player.speedY());
}
if(key == 'd') {
player.right();
world.offXY(player.speedX(),player.speedY());
}
*/

if(key == OF_KEY_LEFT) {
//cout << "rotate left" << endl;
//world.rotateLeft();
}

if(key == OF_KEY_RIGHT) {
//world.rotateRight();
}

} 

void ofApp::mouseMoved(int x,int y) {
mouse.x = x;
mouse.y = y;
}
