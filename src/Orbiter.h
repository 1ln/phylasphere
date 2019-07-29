#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

void radius(float r);
void speed(float s);
void rotationalCenter(float cx, float cy);

void setup();
void update();
void draw();

private:

float _s;
float _a;
float _r;
ofLight _light;
float _cx;
float _cy;
float _x;
float _y;

};

#endif
