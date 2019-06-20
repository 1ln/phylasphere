#include "Plateau.h"

Plateau::Plateau(float x,float y,Formations form) {
_x = x;
_y = y;
_xn = 0;
_yn = 0;
_scl = 100;
_n = 0;
_s = 16;
_h = 0;
_form = form;
}

void Plateau::formations() {
if (_form == HILLY) {
_h = heightNoise(_x,_y);
} else if(_form == JAGGED) {
_h = ofRandom(0,1)*100;
} else if(_form == POOLS) {
_h = 0;
}
}

float Plateau::heightNoise(float xn,float yn) {
_xn = xn;
_yn = yn;
_n = ofNoise(_xn * _scl,_yn * _scl);
return _n;
}

void Plateau::setColor(float r,float g,float b) {
for(int i = 0; i < 6; ++i) { 
plateau.setSideColor(i,ofColor(r,g,b));
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
formations();
plateau.set(_s,_s,_h);
plateau.setPosition(_x,_y,_h/2);
} 
 
void Plateau::drawPlateau() {
    plateau.draw();
    setColor(10,10,10);
}

void Plateau::draw() { 
drawPlateau();
//ofNoFill();
//cout << plateau.getMesh().getNumVertices() << endl; 
//ofSetColor(0,c,0,255);
}

void Plateau::update() {
//plateau.set(_r,_h,_r);
//plateau.setPosition(_x,_y,0);
}
