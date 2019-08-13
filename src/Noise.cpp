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

float Noise::octave(int octaves,float x,float p,float l) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < octaves; ++i) { 

    _result += ofNoise(x*_freq) * _amp;
    _amp *= p;
    _freq *= l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}

float Noise::octave2d(int octaves,float x,float y,float p,float l) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < octaves; ++i) { 

    _result += ofNoise(x*_freq,y*_freq) * _amp;
    _amp *= p;
    _freq *= l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}


float Noise::octave3d(float x,float y,float z) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < _octaves; ++i) { 

    _result += ofNoise(x*_freq,y*_freq,z*_freq) * _amp;
    _amp *= _p;
    _freq *= _l;

}

_result = ofMap(_result,0,1.5,0,1);
return _result;

}

