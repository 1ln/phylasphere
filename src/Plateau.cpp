#include "Plateau.h"

Plateau::Plateau() {
_step = 0;
_px = 0;
_py = 0;
_x = 0;
_y = 0;
_radius = 0;
_new_radius = 0;
_radius_offset = 0;
_height = 0;
} 

void Plateau::setPosition(float px,float py) {
_px = px;
_py = py;
}

void Plateau::setRadius(float radius) { 
_radius = radius;
}

void Plateau::setSteps(float steps) {
_step = (2*PI)/steps;
}

void Plateau::setHeight(float height) {
_height = height;
} 

void Plateau::setAmountOffset(float offset) {
_radius_offset = offset;
}

void Plateau::setup() {

//for(int i = 0; i < 5; ++i) {
//side[i].getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
//}

floor.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
ceiling.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
generatePoints();
 
} 
 
void Plateau::drawPlateau() {

    //for(int i = 0; i < 5; ++i) {
    //side[i].draw();
    //}

    floor.draw(); 
    ceiling.draw();
}

void Plateau::generatePoints(){

_new_radius = _radius;
    for(float theta = 0; theta <= 2*PI; theta += _step) {
        _new_radius = _radius + ofRandom(_radius_offset)*ofNoise(_x,_y);
        _x = _px + _new_radius * cos(theta);
        _y = _py - _new_radius * sin(theta); 
        vx.push_back(_x);
        vy.push_back(_y);
        vtheta.push_back(theta);
        vradius.push_back(_new_radius);
        floor.getMesh().addVertex(ofVec3f(_x,_y,0));
        
        }
        for(unsigned int i = 0; i < 5; ++i) {
        ceiling.getMesh().addVertex(ofVec3f(vx[i],vy[i],35));
        }
/*
        for(unsigned int i = 0; i < 5; ++i) {
        side.getMesh().addVertex(ofVec3f(vx[i],vy[i],0));
        side.getMesh().addVertex(ofVec3f(vx[i].vy[i],35));
        side.getMesh().addVertex(ofVec3f(vx[i+1],vy[i+1],0));
        side.getMesh().addVertex(ofVec3f(vx[i+1].vy[i+1],35));
        }  
*/
}

void Plateau::draw() { 
drawPlateau();
//ofNoFill();
//cout << plateau.getMesh().getNumVertices() << endl; 
ofSetColor(255,0,0,255);
//ofDrawLine(_px+(vradius[2]+45)*cos(vtheta[2]),_py-(vradius[2]+45)*sin(vtheta[2]),vx[2],vy[2]);
}

void Plateau::update() {

}
