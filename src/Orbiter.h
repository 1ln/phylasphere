#ifndef _Orbiter
#define _Orbiter

#include "ofMain.h"

class Orbiter {

public:
Orbiter();

float getRadius();
void setRadius(float radius);
void setSpeed(float speed);
void speedIncrease(float inc,float lim);
void speedDecrease(float inc,float lim);
void setPosition(float x,float y);

void setup();
void update();
void draw();

private:

float _speed;
float _radius;
float _x;
float _y;

};

#endif
