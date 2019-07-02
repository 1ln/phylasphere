#ifndef _Test
#define _Test

#include "ofMain.h"

class Test {

public:
Test();

void height(float h);
void position(float x,float y);

void setup();
void update();
void draw();

ofBoxPrimitive box;

//vector <float> vx;

private:

float _x;
float _y;
float _h;

};

#endif
