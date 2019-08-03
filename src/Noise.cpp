#include "Noise.h"

Noise::Noise() {
_freq = 1;
_amp = 1;
_total_amp = 0;
_result = 0;
} 

float Noise::octave(int octaves,float x,float y,float p,float l) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < octaves; ++i) { 

_result += ofNoise(x*_freq,y*_freq) * _amp;
_amp *= p;
_freq *= l;
//_total_amp += _amp;

}
//cout << "result" << _result << endl;
//_result = ofNormalize(_result,0,1);
_result = ofMap(_result,0,1.5,0,1);
//_result /= _total_amp;
return (_result);

}
