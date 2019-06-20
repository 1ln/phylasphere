#ifndef _Plateau
#define _Plateau

#include "ofMain.h"
#include "geology.h"

class Plateau {

public:
Plateau(float x,float y,Formations form);
 
void drawPlateau();
void formations();
void setColor(float r,float g,float b);
void setHeight(float h);
void setSize(float s);
void setPosition(float x,float y);
float heightNoise(float xn,float yn);

void setup();
void update();
void draw();

ofBoxPrimitive plateau;

private:
 
Formations _form;
float _scl;
float _xn;
float _yn;
float _n;
float _s;
float _x;
float _y;
float _h;
float c;
};

#endif
