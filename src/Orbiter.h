#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

void radius(float r);
void speed(float s);
void center(ofVec3f c);

ofVec3f rotate(ofVec3f c,ofVec3f p);

private:

float _s;
float _a;
float _r;

};

#endif
