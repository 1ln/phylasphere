#ifndef  _Lightpanel
#define  _Lightpanel

#include "ofMain.h"

class Lightpanel {

public:
Lightpanel();
 
void setup();
void update();
void draw();

void wh(float w, float h);
void loc(ofVec3f p);

private:

ofLight light;
ofColor _c;

ofVec3f _p;
float _w;
float _h;

};

#endif
