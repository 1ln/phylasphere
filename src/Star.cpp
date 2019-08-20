#include "Star.h"

Star::Star() {

_r = ofRandom(50,250);
_p = ofVec3f(0,0,0);


}

void Star::setup() {

light.setPosition(_p);

ico.set(_r,2);
ico.setPosition(_p);

}

void Star::draw() {

light.enable();
ico.drawWireframe();

}

void Star::update() {
} 


