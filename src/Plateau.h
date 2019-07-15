#ifndef _Plateau
#define _Plateau

#include "ofMain.h"

class Plateau {

public:
Plateau(float x,float y,float h,ofColor c,bool light);
 
void drawPlateau();
void colorSides();
void setHeight(float h);
void addX(int x);
void addY(int y);
float X();
float Y();
void setSize(float s);
void setPosition(float x,float y);

void setup();
void update();
void draw();

ofBoxPrimitive box;

private:

ofLight light;
bool _light;
float _s;
float _x;
float _y;
float _h;
ofColor _c;
ofMaterial material;
 

};

#endif
