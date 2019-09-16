#include "Noise.h"

Noise::Noise() {

_freq = 1.0;
_amp = 1.0;
_total_amp = 0.0;
_result = 0.0;
_octaves = 4;
_l = 2.0;
_p = 0.5;

ray_origin_ = ofVec3f(0,0,0);
ray_direction_ = ofVec3f(0,0,0);
ray_ = ofVec3f(0,0,0);


} 

void Noise::setCamera(ofCamera &cam) {
cout << cam.getPosition() << endl;
}

//void Noise::setWidth(float w) {
//viewport_width_ = w;
//} 

//void Noise::setHeight(float h) {
//viewport_height_ = h;
//}

void Noise::octaves(int octaves) {
_octaves = octaves;
}

void Noise::lacunarity(float l) {
_l = l;
}

void Noise::persistance(float p) {
_p = p;
} 

float Noise::fb(float x) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < _octaves; ++i) { 

    _result += ofNoise(x*_freq) * _amp;
    _amp *= _p;
    _freq *= _l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}

float Noise::fb2(float x,float y) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < _octaves; ++i) { 

    _result += ofNoise(x*_freq,y*_freq) * _amp;
    _amp *= _p;
    _freq *= _l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}


float Noise::fb3(ofVec3f p ) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < _octaves; ++i) { 

    _result += ofNoise(p.x*_freq,p.y*_freq,p.z*_freq) * _amp;
    _amp *= _p;
    _freq *= _l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}

ofVec3f Noise::getCameraRays(ofCamera &cam) {

ray_origin_.set( cam.getGlobalPosition() );
ray_direction_.set(ofVec3f(0,0,-1));

for(int i = 0; i < 450; ++i) {
    for(int j = 0; j < 450; ++j) {
    ray_ = ray_origin_ + j * ray_direction_;
    //rays_.push(ray_); 
    }
}

return ray_;

}


float Noise::sphereSDF(glm::vec3 p,float radius) {

return glm::length(p) - radius;

}






