#include "Planet.h"

Planet::Planet() {
_step = (2*PI)/100;
_px = 250;
_py = 250;
_x = 0;
_y = 0;
_radius = 45;
_new_radius = 0;
_radius_offset = 0;
} 

void Planet::setPosition(float px,float py) {
_px = px;
_py = py;
}

void Planet::setRadius(float radius) { 
_radius = radius;
}

void Planet::setSteps(float step) {
_step = (2*PI)/step;
}

void Planet::setAmountOffset(float offset) {
_radius_offset = offset;
}

void Planet::setup(){

_new_radius = _radius;

    for(float theta = 0; theta <= 2*PI; theta += _step) {
        _new_radius = _radius + ofRandom(_radius_offset)*ofNoise(_x,_y);
        _x = _px + _new_radius * cos(theta) ;
        _y = _py - _new_radius * sin(theta) ;
        path.lineTo(_x,_y);
        }
  
        path.close();
        path.setFilled(true);
        path.setFillColor(ofColor::grey);
   
}

void Planet::draw() {
path.draw();
}

void Planet::update() {

}
