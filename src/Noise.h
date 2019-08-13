#ifndef _Noise
#define _Noise

#include "ofMain.h"

class Noise {

public:
Noise();
 
void octaves(int octaves);
void lacunarity(float l);
void persistance(float p);

float octave(int octaves,float x,float p,float l);
float octave2d(int octaves,float x,float y,float p,float l);
float octave3d(float x,float y,float z );

private:

float _octaves;
float _l;
float _p;

float _result;

float _freq;
float _amp;

float _total_amp;

};

#endif
