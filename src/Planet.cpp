#include "Planet.h"

Planet::Planet() {
_step = 0;
_px = 0;
_py = 0;
_x = 0;
_y = 0;
_radius = 0;
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

void Planet::setSteps(float steps) {
_step = (2*PI)/steps;
}

void Planet::setAmountOffset(float offset) {
_radius_offset = offset;
}

void Planet::setup() {
generatePoints();
}
 
void Planet::drawPlanet() {
ofSetColor(125,125,125,255);
ofFill();
ofBeginShape();
for(unsigned int i = 0; i < vx.size(); i++) {
    ofVertex(vx[i],vy[i]);
}
ofEndShape();
}

void Planet::generatePoints(){

_new_radius = _radius;
    for(float theta = 0; theta <= 2*PI; theta += _step) {
        _new_radius = _radius + ofRandom(_radius_offset)*ofNoise(_x,_y);
        _x = _px + _new_radius * cos(theta);
        _y = _py - _new_radius * sin(theta);
        vx.push_back(_x);
        vy.push_back(_y);
        vtheta.push_back(theta);
        vradius.push_back(_new_radius); 
        }
}

void Planet::draw() {
drawPlanet();
ofSetColor(255,0,0,255);
ofDrawLine(_px+(vradius[2]+25)*cos(vtheta[2]),_py-(vradius[2]+25)*sin(vtheta[2]),vx[2],vy[2]);
}

void Planet::update() {

}
