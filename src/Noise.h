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
float fb3(ofVec3f p);

float sphereSDF(glm::vec3 p,float radius);

void setCamera(ofCamera &cam);
ofVec3f getCameraRays(ofCamera &cam);

private:

float _octaves;
float _l;
float _p;

float _result;

float _freq;
float _amp;

float _total_amp;

ofVec3f ray_origin_;
ofVec3f ray_direction_;
ofVec3f ray_;

};

#endif
