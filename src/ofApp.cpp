#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(player.getX(),player.getY(),945));
//cam.lookAt(ofVec3f(0,0,0));
cam.lookAt(player.getPosition());
cam.orbitDeg(0,45,945,ofVec3f(0,0,0));
cam.enableOrtho();

player.setRadius(10);
player.setPosition(w/2,h/2);
 
//plateau.setPosition(250,250);
//plateau.setHeight(45); 
//plateau.setup();
cam.setParent(player.player);
light.setAmbientColor(ofColor(255,255,255));
light.setParent(player.player);
light.setPosition(player.getX(),player.getY(),1500);
world.setup();
}

void ofApp::update() {
//plateau.update();
//cam.lookAt(player.getPosition());
}

void ofApp::draw() { 
cam.begin();
light.enable();
player.draw();
world.draw();
//ofDrawBox (200,250,0,25,25,100);
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
