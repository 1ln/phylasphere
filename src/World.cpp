#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_height = 0;
_buffer = 16;
_tile_size = 8;
//_type = "";
_scale = 0.001;
} 

void World::form() {
for(int i = -_buffer+(-_w); i <= _buffer+_w; i+=_tile_size) {
    for(int j = -_buffer+(-_h) ; j <= _buffer+_h; j+=_tile_size) {
    tileType(i,j,0.001);
    //_height = 100;
    tile.push_back(Plateau(i,j,_height,_c));
    }
}

} 

void World::tileType(float i,float j,float scale) {
_n = ofNoise(i*_scale,j*_scale);
_scale = scale;
if(_n < 0.25) {
_height = 0;
_c.set(0,0,100,45);
} else {
_c.set(0,_n*255,0);
_height = _n * 100 ;
}
}

void World::setup() {
//world_plane.setPosition(ofVec3f(0,0,0));
form();

for(int i = 0; i < tile.size(); ++i) {
tile[i].setSize(_tile_size);
tile[i].setup();
}
}

void World::rotateLeft() {
world_plane.rotateDeg(-45,0,0,1);
}

void World::rotateRight() {
world_plane.rotateDeg(45,0,0,1);
}

void World::draw() {
//cout << tile.size() << endl;
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].draw();
//ofTranslate(_w/2,_h/2,0);
//cout << i << endl;
//ofColor(255,0,0,255);
}
}

void World::update() {
}


