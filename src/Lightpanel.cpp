#include "Lightpanel.h"

Lightpanel::Lightpanel() {
_w = 4;
_h = 4;
_p = ofVec3f(0,0,0);
_c = ofColor(255,255,255);
}
 
void Lightpanel::setup() {

light.setAreaLight(_w,_h);
light.setPosition(_p);

} 

void Lightpanel::draw() {

light.enable();

}

void Lightpanel::update() {
light.setAttenuation(.00001,0.00001,0.33);
}

void Lightpanel::loc(ofVec3f p) {

_p = p;

}

void Lightpanel::wh(float w,float h) {

_w = w;
_h = h;

}
