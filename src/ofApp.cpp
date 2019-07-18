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

//player.setup();
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
//world.lights_enable();
}

void ofApp::keyPressed(int key) {


if(key == 'a') {
}

if(key == OF_KEY_RETURN) {
}

} 

void ofApp::mouseMoved(int x,int y) {
mouse.x = x;
mouse.y = y;
}
