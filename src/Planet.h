#ifndef _Planet
#define _Planet

#include "ofMain.h"

class Planet {

public:
Planet();

void drawPlanet();
void generatePoints();
void setRadius(float radius);
void setAmountOffset(float offset);
void setSteps(float step);
void setPosition(float px,float py);

void setup();
void update();
void draw();

ofPath path;

vector <float> vx;
vector <float> vy;
vector <float> vtheta;
vector <float> vradius;

private:

float _step;
float _radius;
float _new_radius;
float _radius_offset;
float _px;
float _py;
float _x;
float _y;

};

#endif
