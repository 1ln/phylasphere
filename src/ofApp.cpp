#include "ofApp.h"

void ofApp::setup() {
ofBackground(0);
w = ofGetWidth();
h = ofGetHeight();

planet.setPosition(w/2,h/2);
planet.setRadius(115);
planet.setAmountOffset(25);
planet.setSteps(25);
planet.setup();

}

void ofApp::update() {
planet.update();
}

void ofApp::draw(){
planet.draw();
}

void ofApp::keyPressed(int key) {

//wsad keys
if(key == 'w') {
cout << "w pressed" << endl;
}

if(key == 's') { 
}

if(key == 'a') {
}

if(key == 'd') {
}

}
