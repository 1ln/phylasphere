#include "Plateau.h"

Plateau::Plateau(float x,float y,float h,ofColor c,bool light) {
_x = x;
_y = y;
_s = 8;
_h = h;
_c = c;
_light = light;
}

void Plateau::colorSides() {
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
//light.setPointLight();
} 
 
void Plateau::drawPlateau() {
    plateau.draw();
    //setColor();
}

void Plateau::draw() { 
drawPlateau();

if(_light == true) {
light.enable();
}

}

void Plateau::update() {
plateau.set(_s,_s,_h);
plateau.setPosition(_x,_y,0);
colorSides();
if(_light == true) {
light.setPosition(_x,_y,_h+5);
light.setAttenuation(.00001,.001,.001);
//light.enable();
}
}
