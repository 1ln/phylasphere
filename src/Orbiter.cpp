#include "Orbiter.h"

Orbiter::Orbiter() {
_x = 0;
_y = 0;
_cx = 0;
_cy = 0;
_radius = 0;
_orbital_radius = 0;
_speed = 0;
}

void Orbiter::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Orbiter::setRotationalCenter(float cx,float cy) {
_cx = cx;
_cy = cy;
}

void Orbiter::setSpeed(float speed) {
_speed = speed;
}

void Orbiter::thrusters(float inc) {
    _speed -= inc;
}

void Orbiter::setRadius(float radius) { 
_radius = radius;
}

float Orbiter::getRadius() {
return _radius;
}

void Orbiter::setup(){
//_orbital_radius = ofDist(_cx,_cy,_x,_y);
_orbital_radius = 350;
//cout << _orbital_radius << endl;
}

void Orbiter::draw() {
//ofPushMatrix();
//ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//ofRotateZRad(_speed);
//cout << _x << endl;
ofDrawCircle(_x,_y,_radius);
//ofPopMatrix();
}

void Orbiter::update() {
//_speed = ofGetLastFrameTime() * .18;
//_speed = .1;
for(float theta = 0; theta < 2*PI; theta+=0.01) {
_x = _cx + (_orbital_radius * cos(theta));
_y = _cy - (_orbital_radius * sin(theta));
//ofDrawCircle(_x,_y,_radius);
}
//cout << _x << endl;
//ofDrawCircle(_x,_y,_radius);
}
