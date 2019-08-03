#include "Icosphere.h"

Icosphere::Icosphere() {

_r = 400;
_center = ofVec3f(0,0,0);
 
}

void Icosphere::setup() {

ico.set(_r,1);

}

void Icosphere::draw() {

ico.drawWireframe();

}

void Icosphere::update() {
} 


