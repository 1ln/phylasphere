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

void init();
void scale(float s);
void rotX(float x);
void rotY(float y);
void rotate45();
void remap();
void tileType(float i,float j);

private:

int _tile_width;
int _buffer;
float _w;
float _h;
float _elevation;
float _n; 
float _scale;
float _r;
int _total_tiles;
ofLight _ambient_lighting;
ofColor _c;
float _steps;
vector <Plateau> tile;
vector <ofBoxPrimitive> box;
bool _light;
float _map_width;
};

#endif
