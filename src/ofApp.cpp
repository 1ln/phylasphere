#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(0,0,945));
//cam.lookAt(ofVec3f(0,0,0));
cam.lookAt(player.getPosition());
cam.orbitDeg(0,45,945,ofVec3f(0,0,0));
cam.enableOrtho();

player.setRadius(10);
player.setPosition(0,0);
 
plateau.setRadius(115);
plateau.setAmountOffset(25);
plateau.setSteps(5);
plateau.setHeight(45); 
plateau.setup();
cam.setParent(player.player);

light.setParent(player.player);
light.setPosition(player.getX(),player.getY(),1500);
}

void ofApp::update() {
plateau.update();
//cam.lookAt(player.getPosition());
}

void ofApp::draw() { 
cam.begin();
light.enable();
player.draw();
ofDrawBox (200,250,0,25,25,100);
//plateau.draw();
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
player.rotateLeft();
}
if(key == 'd') {
player.rotateRight();
}

} 

void ofApp::keyReleased(int key) {
}
