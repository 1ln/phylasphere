#include "Orbiter.h"

Orbiter::Orbiter() {
_x = 0;
_y = 0;
_radius = 5;
_speed = 0;
} 

void Orbiter::setPosition(float x,float y) {
_x = x;
_y = y;
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
  
}

void Orbiter::draw() {
ofPushMatrix();
ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
ofRotateZRad(_speed);
ofDrawCircle(_x,_y,_radius);
ofPopMatrix();
}

void Orbiter::update() {
_speed += ofGetLastFrameTime() * .18;
}
