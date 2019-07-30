#include "Noise.h"

Noise::Noise() {
_freq = 1;
_amp = 1;
_result = 0;
} 

float Noise::octave(int octaves,float x,float y,float p,float l) {

_freq = 1;
_amp = 1;
_result = 0;

for(int i = 0; i < octaves; ++i) { 
_result += ofSignedNoise(x*_freq,y*_freq) * _amp;
_amp *= p;
_freq *= l;

}
//cout << _result << endl;
//_result = ofNormalize(_result,0,1);
return abs(_result); 
}
