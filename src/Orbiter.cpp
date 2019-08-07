#include "Orbiter.h"

Orbiter::Orbiter() {
_x = 0;
_y = 0;
_cx = 0;
_cy = 0;
_r = 250;
_s = 0.001;
_a = ofRandom(0,TWO_PI);
}

void Orbiter::center(float cx,float cy) {
_cx = cx;
_cy = cy;
}

void Orbiter::speed(float s) {
_s = s;
} 

void Orbiter::radius(float r) { 
_r = r;
}

void Orbiter::setup(){

_light.setPointLight();

_light.setDiffuseColor(ofFloatColor(.01,.01,.085,1));
_light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
//_light.setAttenuation(.001,.001,1);

}

void Orbiter::draw() {
_light.enable();
_light.draw();
}

void Orbiter::update() {
_a += _s;
_x = _cx + cos(_a) * _r;
_y = _cy + sin(_a) * _r;

_light.setPosition(_x,_y,0);

}
