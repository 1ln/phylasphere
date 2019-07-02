#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_height = 0;
_buffer = 16;
_tile_size = 8;
_scale = 0;
_xoff = 0;
_yoff = 0;
_light = false;
} 

void World::form() {
for(int i = -256; i <= 256; i+=_tile_size) {
    for(int j = -256; j <= 256; j+=_tile_size) {
    tileType(i+(_xoff)+_r,j+(_yoff)+_r);
    tile.push_back(Plateau(i,j,_height,_c,_light));
    }
}
}

void World::scale(float s) {
_scale = s;
}

void World::tileType(float i,float j) {
_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
if(_n < .48) {
_height = 0;
_c.set(0,5,75*_n,255);
_light = false;
}
    if(_n > .48 && _n < .51) {
    _height = _n*_scale;
    _c.set(_n*15,_n*15,_n*15,255);
    _light = true;
}
    if(_n > .51) {

    _c.set(_n*15,_n*15,_n*15,255);
    _height =  _n * _scale;
    _light = false;     
}

}

void World::setup() {
 
ofSeedRandom(); 

scale(100);
_r = ofRandom(0,4000000) ;
//_level = ofRandom(.4,.85);

form();

for(int i = 0; i < tile.size(); ++i) {
//tile[i].setSize(_tile_size);
tile[i].setup();
}

}

void World::offXY(float xoff, float yoff) {
_xoff = xoff;
_yoff = yoff;
tile.clear();
}

void World::rotate45() {
world_plane.rotateDeg(-45,0,0,1);
}

void World::rotX(float x) {
world_plane.rotateDeg(x,0,0,1);
}

void World::rotY(float y) {
world_plane.rotateDeg(y,0,0,1);
}

void World::draw() {
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].draw();
}
}

void World::update() {

form();
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].update();
}
}

