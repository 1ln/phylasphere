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
void setHeight(float h);
void setOrbiting(bool orbiting);
void setPosition(ofVec3f p);
void setOrbitalCenter(ofVec3f c);
void setDistanceFromCenter(float d);
void setRotatingOnAxis(bool rotating); 

void setup();
void update();
void draw();

ofIcoSpherePrimitive ico;
ofMesh mesh;
of3dPrimitive primitive;
//ofShader shader;

ofMaterial mat;
ofColor c;

private:

float _r;
float _n;
float scale_;
float radius_;
float height_;
ofVec3f position_;
ofVec3f orbital_center_;
float distance_from_center_;
bool rotate_on_axis_;
bool orbiting_;


};

#endif
