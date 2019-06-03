#include "ofApp.h"

void ofApp::setup() {
ofBackground(0);
w = ofGetWidth();
h = ofGetHeight();

planet.setPosition(w/2,h/2);
planet.setRadius(350);
planet.setAmountOffset(25);
planet.setSteps(250);
planet.setup();
}

void ofApp::update() {
planet.update();
}

void ofApp::draw(){
planet.draw();
}
