#ifndef _Player
#define _Player

#include "ofMain.h"

class Player {

public:
Player();

void drawPlayer();
void setRadius(float radius);
void setPosition(float x,float y);
 
void back(); 
void forward();
void rotateLeft();
void rotateRight();

void setup();
void update();
void draw();

ofBoxPrimitive ico;
//ofIcoSpherePrimitive ico;
 
private:

float _radius;
float _x;
float _y;

};

#endif
