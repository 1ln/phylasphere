#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

void setNode(ofNode n);
void orbitalRadius(float r);
void orbitalSpeed(float s);
void orbitalCenter(ofVec3f c);
void rotationalSpeed(float s);
void position(ofVec3f p);

void orbit(ofNode &n);
void rotateAxis(ofNode &n,ofVec3f axis);

private:

float orbital_speed_;
float rotational_progression_;
float rotational_speed_;
float orbital_progression_;
float orbital_radius_;

ofVec3f position_;
ofVec3f orbital_center_;

ofNode n_;

};

#endif
