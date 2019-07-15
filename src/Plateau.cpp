#include "Plateau.h"

Plateau::Plateau(float x,float y,float h,ofColor c,bool light) {
_x = x;
y = y;
_s = 4;
_h = h;
_c = c;
_light = light;
}

void Plateau::colorSides() {
for(int i = 0; i < 6; ++i) { 
box.setSideColor(i,_c);
} 
ofSetColor(15,15,15,255);
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
} 

void Plateau::draw() {
update();
material.begin();
box.draw();
material.end();

if(_light == true) {
light.enable();
}

}

void Plateau::update() {
box.set(_s,_s,_h);
box.setPosition(_x,_y,0);
//colorSides();
if(_light == true) {
light.setPosition(_x,_y,_h+5);
light.setAttenuation(.00001,.001,.001);
//light.setPointLight();
}
material.setDiffuseColor(ofColor(5,5,5,255));


}
