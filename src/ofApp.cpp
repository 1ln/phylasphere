#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(w/2,h/2,945));
cam.lookAt(ofVec3f(w/2,h/2,0));
//cam.lookAt(player.getPosition());
cam.orbitDeg(0,45,945,ofVec3f(0,0,0));
//cam.rotate(45);
cam.enableOrtho();
//cam.rotateDeg(45);

//player.setRadius(10);
player.setPosition(0,0);
 
//plateau.setPosition(250,250);
//plateau.setHeight(45); 
//plateau.setup();
cam.setParent(player.player);
light.setAmbientColor(ofColor(255,255,255));
//light.setParent(player.player);
light.setPosition(player.getX(),player.getY(),2500);
player.rotateLeft();
world.setup();
}

void ofApp::update() {
//plateau.update();
//cam.lookAt(ofVec3f(w/2,h/2,0));
}

void ofApp::draw() { 
cam.begin();
light.enable();
player.draw();
world.draw();
ofDrawBox (0,0,8,16,16,16);
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

if(key == 'OF_KEY_LEFT') {
}
if(key == 'OF_KEY_RIGHT') {
}

} 

void ofApp::keyReleased(int key) {
}
