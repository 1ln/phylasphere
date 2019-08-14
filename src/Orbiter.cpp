#include "Orbiter.h"

Orbiter::Orbiter() {

_r = 0;
_s = 0.001;
_a = ofRandom(0,TWO_PI);

}

void Orbiter::speed(float s) {
_s = s;
} 

void Orbiter::radius(float r) { 
_r = r;
}

//void Orbiter::setup(){

//}

//void Orbiter::draw() {

//}

ofVec3f Orbiter::rotate(ofVec3f c,ofVec3f p) {
_a += _s;
p.x = c.x + cos(_a) * _r;
p.y = c.y + sin(_a) * _r;

return p;
}
