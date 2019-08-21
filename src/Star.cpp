#include "Star.h"

Star::Star() {

_r = ofRandom(1,10);
_p = ofVec3f(1000,0,0);


}

void Star::setup() {

light.setPosition(_p);

ico.set(_r,2);
ico.setPosition(_p);

}

void Star::draw() {

light.enable();
//ico.drawWireframe();
ofDrawSphere(_p,_r);


}

void Star::update() {
} 


