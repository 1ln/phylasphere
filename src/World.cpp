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
} 

void World::form() {
for(int i = -256; i <= 256; i+=_tile_size) {
    for(int j = -256; j <= 256; j+=_tile_size) {
    tileType(i+(_xoff),j+(_yoff),100);
    tile.push_back(Plateau(i,j,_height,_c));
    }
}
}

void World::tileType(float i,float j,float scale) {
_scale = scale;
_n = noise.octave(_r2,i*_r*_scale,j*_r*_scale,_r3,_r1);
if(_n < .25) {
//_type = WATER;
} else {
//_type = LAND;
_c.set(0,_n*100,0);
     //if(_n < .6) {
    //_height =  _n1 * _r2*550  ;
    //} else if ( _n < .85 ) {
    _height = _n * 100;
    //} else {
    //_height = _n * _r2*95;
//}
}
}

void World::setup() {

ofSeedRandom();

_r = ofRandom(0,.0001);
_r1 = ofRandom(0,.75);
_r2 = ofRandom(1,8);
_r3 = ofRandom(0,1);

form();

for(int i = 0; i < tile.size(); ++i) {
//tile[i].setSize(_tile_size);
//tile[i].setup();
}

}

void World::setXYOff(float xoff, float yoff) {
_xoff = xoff;
_yoff = yoff;
tile.clear();
}

void World::rotateLeft() {
world_plane.rotateDeg(-45,0,0,1);
}

void World::rotateRight() {
world_plane.rotateDeg(45,0,0,1);
}

void World::draw() {
//cout << tile.size() << endl;
for(int i = 0; i < tile.size(); ++i) {
tile[i].draw();
//ofTranslate(_w/2,_h/2,0);
//cout << i << endl;
//ofColor(255,0,0,255);
}
}

void World::update() {
form();
for(int i = 0; i < tile.size(); ++i) {
tile[i].update();
}
}

