#ifndef _Utility
#define _Utility

#include "ofMain.h"

class Utility {

public:
Utility();

float randAngleSqrt(float radius);
float randAngle();
float annulusDistance(float inner_radius, float outer_radius);

private:

float _x;
float _y;
float _distance;
float _theta;

};

#endif
