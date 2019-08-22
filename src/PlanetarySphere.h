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

void setRadius(float r);
void setOrbiting(bool orbiting);
void setPosition(ofVec3f p);
void setOrbitalCenter(ofVec3f c);
void setDistanceFromCenter(ofVec3f d);
void setRotatingOnAxis(bool rotating); 

void setup();
void update();
void draw();

ofIcoSpherePrimitive ico;
ofMesh mesh;
of3dPrimitive primitive;

ofMaterial mat;
ofColor c;

private:

bool orbiting_;

float _r;
float _n;
float _scale;

float _radius;
ofVec3f position_;
ofVec3f _orbital_center;
float _distance_from_center;

};

#endif
