#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

cam.setPosition(ofVec3f(0,0,945));
cam.lookAt(ofVec3f(0,0,0));
cam.orbitDeg(0,45,945,ofVec3f(0,0,0));
plateau.setRadius(115);
plateau.setAmountOffset(25);
plateau.setSteps(5);
plateau.setHeight(45); 
plateau.setup();

light.setPointLight();
light.setPosition(ofVec3f(-100,100,100));
}

void ofApp::update() {
plateau.update();
}

void ofApp::draw() { 
cam.begin();
light.enable();
//ofDrawBox(0,0,0,100,100,100);
plateau.draw();
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
