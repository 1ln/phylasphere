#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

void radius(float r);
void speed(float s);
void center(float cx, float cy);

void setup();
void update();
void draw();

private:

ofLight _light;

float _s;
float _a;
float _r;
float _cx;
float _cy;
float _x;
float _y;

};

#endif
