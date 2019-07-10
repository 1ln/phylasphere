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
//for(int i = 0; i < 6; ++i) { 
//plateau.setSideColor(i,_c);
//} 
//ofSetColor(15,15,15,255);
}

void Plateau::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Plateau::setHeight(float h) {
_h = h;
}

float Plateau::X() {
return _x;
}

float Plateau::Y() {
return _y;
}

void Plateau::addX(int x) {
_x += x;
}

void Plateau::addY(int y) {
_y += y;
}

void Plateau::setSize(float s) {
_s = s;
}

void Plateau::setup() {
//c = ofRandom(0,1) *100;
//plateau.set(_s,_s,_h);
//plateau.setPosition(_x,_y,0);
//light.setPointLight();
//light.setAttenuation(0.00001,.001,.001);
//material.setEmissiveColor(ofColor(25,25,255,155));
} 

void Plateau::draw() {

material.begin();
plateau.draw();
material.end();

if(_light == true) {
light.enable();
}

}

void Plateau::update() {
plateau.set(_s,_s,_h);
plateau.setPosition(_x,_y,0);
//colorSides();
if(_light == true) {
light.setPosition(_x,_y,_h);
light.setAttenuation(.00001,.001,.001);
//light.setPointLight();
}
//material.setAmbientColor(ofColor(15,15,15,255));
material.setEmissiveColor(ofColor(15,15,15,255));

//light.enable();
//}
}
