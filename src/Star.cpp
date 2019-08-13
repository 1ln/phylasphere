#include "Star.h"

Star::Star() {

_r = 400;
_p = ofVec3f(0,0,0);
 
}

void Star::setup() {

ico.set(_r,5);
ico.setPosition(_p);

}

void Star::draw() {

ico.drawWireframe();

}

void Star::update() {
} 


