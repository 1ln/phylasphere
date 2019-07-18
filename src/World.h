#ifndef _World
#define _World

#include "ofMain.h"
//#include "Plateau.h"
#include "Noise.h"
#include "deque"

class World {

public:
World();
 
ofPlanePrimitive world_plane;
ofBoxPrimitive box;
Noise noise2;
Noise noise;

void draw(); 
void update();
void setup();

void init();
void scale(float s);
void rotX(float x);
void rotY(float y);
void sideColor();
void rotate45();
void remap();
void tileType(float i,float j);

private:

int _tile_width;
float _hue;
float _w;
float _h;
float _elevation;
float _n;
float _n1;
float _scale;
float _r;
int _total_tiles;
ofLight _ambient_lighting;
ofColor _c;
float _steps;
int _x_width;
ofLight light;
ofColor light_col;
ofColor material_col;
float _spotlight_x;
float _spotlight_y;
deque <ofLight> lights;
ofMaterial material;
deque <ofBoxPrimitive> boxes;
deque <ofMaterial> materials;
bool _light;
float _map_width;
};

#endif
