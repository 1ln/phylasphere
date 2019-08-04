#ifndef _DistanceRender
#define _DistanceRender

#include "ofMain.h"

class DistanceRender {

public:
DistanceRender();

float box(ofVec3f p,ofVec3f b);
float sphere(ofVec3f p, ofVec3f c,float r);

fixed4 ray_march(ofVec3f o,ofVec3f d);

//void setup();
//void update();
//void draw();

//vector <float> vx;

private:


};

#endif
