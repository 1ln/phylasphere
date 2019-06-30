#ifndef _World
#define _World

#include "ofMain.h"
#include "Plateau.h"
#include "Player.h"
#include "Noise.h"

class World {

public:
World();
 
ofPlanePrimitive world_plane;
Noise noise;

Player player; 

void draw(); 
void update();
void setup();

void form();
void rotateLeft();
void rotateRight();
void setXYOff(float xoff, float yoff);
void tileType(float i,float j,float scale);

private:

int _tile_size;
int _buffer;
float _xoff;
float _yoff;
float _w;
float _h;
float _height;
float _n; 
float _level;
float _scale;
float _r;
ofColor _c;
float _step;
vector <Plateau> tile;
//string _type;

};

#endif
