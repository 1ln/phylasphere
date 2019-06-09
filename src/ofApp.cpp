#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(0,0,945));
cam.lookAt(ofVec3f(0,0,0));
cam.orbitDeg(0,45,945,ofVec3f(0,0,0));
planet.setRadius(115);
planet.setAmountOffset(25);
planet.setSteps(25);
planet.setHeight(10); 
planet.setup();
 
}

void ofApp::update() {
planet.update();
}

void ofApp::draw() { 
cam.begin();
//ofDrawBox(0,0,0,100,100,100);
planet.draw();
cam.end();
}

void ofApp::keyPressed(int key) {

//w key
if(key == 'w') {
//cout << "w pressed" << endl;
}

} 

void ofApp::keyReleased(int key) {
}
