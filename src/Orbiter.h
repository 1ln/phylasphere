#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

void radius(float r);
void speed(float s);

ofVec3f rotate(ofVec3f c,ofVec3f p);

//void setup();
//void update();
//void draw();

private:

float _s;
float _a;
float _r;

};

#endif
