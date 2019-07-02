#ifndef _World
#define _World

#include "ofMain.h"
#include "Plateau.h"
#include "Noise.h"

class World {

public:
World();
 
ofPlanePrimitive world_plane;
Noise noise;

void draw(); 
void update();
void setup();

void form();
void scale(float s);
void rotX(float x);
void rotY(float y);
void rotate45();
void offXY(float xoff, float yoff);
void tileType(float i,float j);

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
bool _light;
};

#endif
