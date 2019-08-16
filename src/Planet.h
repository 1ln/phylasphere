#ifndef _Planet
#define _Planet

#include "ofMain.h"
#include "Noise.h"
#include "Orbiter.h"
#include "SignedDistance.h"

class Planet {

public:

Planet();

SignedDistance dist;
Noise noise;
Orbiter orb;

void radius(float r);
void orbiting(ofNode n);
ofVec3f g_Position();
void orbital_center(ofVec3f c);
float intersect(ofVec3f p);

void setup();
void update();
void draw();

ofIcoSpherePrimitive ico;
ofMesh mesh;
ofColor c;

private:

float _n;
float _r;
ofVec3f _p;
ofVec3f _orbital_center;
ofVec3f np;

};

#endif
