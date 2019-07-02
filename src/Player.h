#ifndef _Player
#define _Player

#include "ofMain.h"

class Player {

public:
Player();

void radius(float r);
void position(float x,float y);
void speed(float s);
float speedX();
float speedY();
float x();
float y(); 
 
void back(); 
void forward();
void left(); 
void right();
void mouseFromWorld(ofVec3f v);
void rotate(float x,float y);

void setup();
void update();
void draw();

ofBoxPrimitive box;
 
private:

float _x;
float _y;
float _r;
float _speed;
float _speedX;
float _speedY;
ofVec3f _v;
ofVec3f _mouse;
};

#endif
