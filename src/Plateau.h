#ifndef _Plateau
#define _Plateau

#include "ofMain.h"

class Plateau {

public:
Plateau(float x,float y,float h,ofColor c);
 
void drawPlateau();
void setColor(float r,float g,float b);
void setHeight(float h);
void setSize(float s);
void setPosition(float x,float y);

void setup();
void update();
void draw();

ofBoxPrimitive plateau;

private:
 
float _s;
float _x;
float _y;
float _h;
float c;
};

#endif
