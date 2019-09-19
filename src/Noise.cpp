#include "Noise.h"

Noise::Noise() {

_freq = 1.0;
_amp = 1.0;
_total_amp = 0.0;
_result = 0.0;
_octaves = 4;
_l = 2.0;
_p = 0.5;

} 

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





