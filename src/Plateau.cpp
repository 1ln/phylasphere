#include "Plateau.h"

Plateau::Plateau(float x,float y,float h,ofColor c) {
_x = x;
_y = y;
_s = 8;
_h = h;
_c = c;
}

void Plateau::setColor() {
for(int i = 0; i < 6; ++i) { 
plateau.setSideColor(i,_c);
}
}

void Plateau::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Plateau::setHeight(float h) {
_h = h;
}

void Plateau::setSize(float s) {
_s = s;
}

void Plateau::setup() {
//c = ofRandom(0,1) *100;
//plateau.set(_s,_s,_h);
//plateau.setPosition(_x,_y,0);
} 
 
void Plateau::drawPlateau() {
    plateau.draw();
    //setColor();
}

void Plateau::draw() { 
drawPlateau();
//ofNoFill();
//cout << plateau.getMesh().getNumVertices() << endl; 
//ofSetColor(0,c,0,255);
}

void Plateau::update() {
plateau.set(_s,_s,_h);
plateau.setPosition(_x,_y,0);
setColor();
}
