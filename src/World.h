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
void tileType(float i,float j,float scale);

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
