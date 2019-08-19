#ifndef _PlanetarySphere
#define _PlanetarySphere

#include "ofMain.h"
#include "Noise.h"
#include "Orbiter.h"

class PlanetarySphere {

public:

PlanetarySphere();

Noise noise;
Orbiter orb;

void radius(float r);
void orbiting(ofNode n);
ofVec3f g_Position();

void setup();
void update();
void draw();

ofIcoSpherePrimitive ico;
ofMesh mesh;

ofMaterial mat;
ofColor c;

private:

float _n;
float _r;
ofVec3f _p;
ofVec3f _orbital_center;
float _distance_from_center;

};

#endif
