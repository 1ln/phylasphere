#ifndef _Player
#define _Player

#include "ofMain.h"

class Player {

public:
Player();

void drawPlayer();
void setRadius(float radius);
void setPosition(float x,float y);
ofVec3f getPosition();
float getSpeedX();
float getSpeedY();
float getX();
float getY();
 
void back(); 
void forward();
void left(); 
void right();

void setup();
void update();
void draw();

ofBoxPrimitive player;
//ofIcoSpherePrimitive player;
 
private:

float _x;
float _y;
float _radius;
float _speedX;
float _speedY;

};

#endif
