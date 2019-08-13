#ifndef _Star
#define _Star

#include "ofMain.h"

class Star {

public:
Star();

void setup();
void draw();
void update();
void radius(float r);

private:

ofIcoSpherePrimitive ico;

float _r;

ofVec3f _p;
ofColor _col;

};

#endif
