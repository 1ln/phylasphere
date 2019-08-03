#ifndef _Icosphere
#define _Icosphere

#include "ofMain.h"

class Icosphere {

public:
Icosphere();

void setup();
void draw();
void update();
//void radius(float r);

private:

ofIcoSpherePrimitive ico;

float _r;

ofVec3f _center;
ofColor _col;

};

#endif
