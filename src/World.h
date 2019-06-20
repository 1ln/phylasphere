#ifndef _World
#define _World

#include "ofMain.h"
#include "geology.h"
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
Formations tileType(float i,float j);

private:

int _tile_size;
int _buffer;
float _w;
float _h;
float _height;
float _n;
float _scale;
vector <Plateau> tile;
//string _type;

};

#endif
