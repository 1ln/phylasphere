#ifndef _Noise
#define _Noise

#include "ofMain.h"

class Noise {

public:
Noise();
 
void octaves(int octaves);
void lacunarity(float l);
void persistance(float p);

float fb(float x);
float fb2(float x,float y);
float fb3(float x,float y,float z );

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
