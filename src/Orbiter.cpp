#include "Orbiter.h"

Orbiter::Orbiter() {
_x = 0;
_y = 0;
_radius = 5;
_speed = .18;
} 

void Orbiter::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Orbiter::setSpeed(float speed) {
_speed = speed;
}

void Orbiter::speedDecrease(float inc,float lim) {
    if(_speed >= lim) {
    _speed -= inc;
    } 
}

void Orbiter::speedIncrease(float inc,float lim) {
    if(_speed <= lim) {
    _speed += inc;
    }
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
ofRotateZRad(ofGetElapsedTimef() * _speed);
ofDrawCircle(_x,_y,_radius);
ofPopMatrix();
}

void Orbiter::update() {
}
