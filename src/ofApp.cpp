#include "ofApp.h"

void ofApp::setup() {

ofBackground(185);
w = ofGetWidth();
h = ofGetHeight();

orbiter.setPosition(w/2,h/8);
orbiter.setRotationalCenter(w/2,h/2);
orbiter.setRadius(15);
orbiter.setup();

planet.setPosition(w/2,h/2);
planet.setRadius(115);
planet.setAmountOffset(25);
planet.setSteps(25);
planet.setup();
 
}

void ofApp::update() {
planet.update();
orbiter.update();
}

void ofApp::draw(){
planet.draw();
//orbiter.draw();
}

void ofApp::keyPressed(int key) {

//wsad keys
if(key == 'w') {
//cout << "w pressed" << endl;
}

if(key == 's') {
orbiter.thrusters(.03);
} else {
} 

if(key == 'a') {
}

if(key == 'd') {
} 

}

void ofApp::keyReleased(int key) {
}
