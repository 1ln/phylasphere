#include "ofApp.h"

void ofApp::setup() {

ofBackground(0);
w = ofGetWidth();
h = ofGetHeight();
world.setup();
cam.setParent(world.world_plane);
cam.lookAt(ofVec3f(0,0,0));
cam.orbitDeg(0,45,1000,ofVec3f(0,0,0));
//cam.enableOrtho();
world.rotate45();
//world.setup();

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
world.draw();
//player.draw();
cam.end();
}

void ofApp::keyPressed(int key) {

if(key == 'w') {
player.forward();
//world.offXY(player.speedX(),player.speedY());
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
