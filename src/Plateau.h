#ifndef _Plateau
#define _Plateau

#include "ofMain.h"

class Plateau {

public:
Plateau(float x,float y,float h,string type);

void drawPlateau();
void solidColor(float r,float g,float b);
void setHeight(float h);
void setPosition(float x,float y);

void setup();
void update();
void draw();

ofBoxPrimitive plateau;

private:

float _r;
float _x;
float _y;
float _h;
string _type;
float c;
};

#endif
