#ifndef _Star
#define _Star

#include "ofMain.h"
//#include "Planet.h"

class Star {

public:
Star();

//Planet planet;

void setup();
void draw();
void update();
void radius(float r);

private:

ofIcoSpherePrimitive ico;
ofLight light;

float _r;

ofVec3f _p;
ofColor _col;

};

#endif
