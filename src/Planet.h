#ifndef _Planet
#define _Planet

#include "ofMain.h"
#include "Noise.h"

class Planet {

public:

Planet();

Noise noise;

void radius(float r);
void position(ofVec3f p);

void setup();
void update();
void draw();

of3dPrimitive ico;
ofMesh mesh;
ofColor c;

private:

float _r;

};

#endif
