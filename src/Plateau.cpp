#include "Plateau.h"

Plateau::Plateau(float x,float y,float h,string type) {
_x = x;
_y = y;
_r = 100;
_h = h;
_type = type;
} 

void Plateau::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Plateau::setHeight(float h) {
_h = h;
} 

void Plateau::setup() {
c = ofRandom(0,1) *100;
plateau.set(_r,_r,_h);
plateau.setPosition(_x,_y,0);
} 
 
void Plateau::drawPlateau() {
    plateau.draw(); 
}


void Plateau::draw() { 
drawPlateau();
//ofNoFill();
//cout << plateau.getMesh().getNumVertices() << endl; 
ofSetColor(0,c,0,255);
}

void Plateau::update() {
//plateau.set(_r,_h,_r);
//plateau.setPosition(_x,_y,0);
}
