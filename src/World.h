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
float tileHeight(float i,float j);

private:

int _tiles;
float _w;
float _h;
float _height;
float _n;
float _scale;
vector <Plateau> tile;
float _buffer;
string _type;

};

#endif
