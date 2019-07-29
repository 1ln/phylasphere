#include "Orbiter.h"

Orbiter::Orbiter() {
_x = 0;
_y = 0;
_cx = 0;
_cy = 0;
_r = 550;
_a = 0;
}

void Orbiter::rotationalCenter(float cx,float cy) {
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
}

void Orbiter::draw() {
_light.enable();
_light.draw();
}

void Orbiter::update() {
_a += 0.00001;
_x = _cx + cos(_a) * _r;
_y = _cy + sin(_a) * _r;

_light.setPosition(_x,_y,0);

}
