#ifndef _World
#define _World

#include "ofMain.h"
#include "Plateau.h"

class World {

public:
World();
 
ofPlanePrimitive world_plane;

void draw(); 
void update();
void setup();

void form();
void rotateLeft();
void rotateRight();
float octaveNoise(float x,float y,float o,float p,float l);
void tileType(float i,float j,float scale);

private:

int _tile_size;
int _buffer;
float _w;
float _h;
float _height;
float _n;
float _n1;
float _n2;
float _r;
float _r1;
float _r2;
float _result;
float _total;
float _total_amp;
float _freq;
float _amp;
ofColor _c;
float _scale;
vector <Plateau> tile;
//string _type;

};

#endif
