#ifndef _Noise
#define _Noise

#include "ofMain.h"

class Noise {

public:
Noise();

float octave(int octaves,float x,float y,float p,float l);

private:

float _result;
float _freq;
float _amp;
float _total_amp;

};

#endif
