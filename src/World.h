#ifndef _World
#define _World

#include "ofMain.h"

#include "feature.h"
#include "Noise.h"

#include "deque"

class World {

public:
World();
 
ofPlanePrimitive world_plane;
ofBoxPrimitive _box;
ofBoxPrimitive _tile_box;
Noise noise2;
Noise noise;

void draw(); 
void update();
void setup();

void init();
void scale(float s);
void input_activated();
void input_deactivate();
void sideColor();
void rotate45();
void remap();
void tileType(float i,float j);

private:

Feature _type;
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
ofColor _c;
float _steps;
int _x_width;
ofLight _spotlight;
float _spotlight_radius;
float _box_radius;
ofColor _light_col;
float _spotlight_x;
float _spotlight_y; 
deque <ofBoxPrimitive> _tile_boxes;
deque <ofBoxPrimitive> _boxes;
bool _light;
float _map_width;
bool _input;
float _start_timer;
};

#endif
