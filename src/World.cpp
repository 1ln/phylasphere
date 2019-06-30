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
    tileType(i+(_xoff)+_r,j+(_yoff)+_r,100);
    tile.push_back(Plateau(i,j,_height,_c));
    }
}
}

void World::tileType(float i,float j,float scale) {
_scale = scale;
_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
//_n1 = noise.octave(1,i*0.0001*_scale,j*_step*_scale,.5,2);
//_n2 = noise.octave(1,i*0.0001*_scale,j*_step*_scale,.25,4);
//_n3 = noise.octave(1,i*0.0001*_scale,j*_step*_scale,.5,4);
//_n4 = noise.octave(1,i*0.0001*_scale,j*_step*_scale,.25,6);
//_n5 = _n1 + _n2 + _n3 + _n4;
if(_n < _level) {
_height = 0;
_c.set(0,100,235,255);
} else {
//_c.set(0,_n*255,0,255);
    //if(_n1 < .45) {
    //cout << _n << endl;
    _c.set(0,_n*_scale,0,255);
    _height =  _n * _scale;
    //} else if ( _n1 < .85 ) {
    //_c.set(0,_n1*255,0,255);
    //_height = _n1 * _scale * 2;
    //} else { 
    //_height = _n1 * _scale * 5;
    //_c.set(0,_n1*255,0,255);
}
//}
//}
//for(int i = 0; i < 100; ++i) { 
//_scale += i;
//}
}

void World::setup() {
ofSeedRandom();
_r = ofRandom(0,4000000) ;
cout << _r << endl;
_level = ofRandom(.4,.85);
form();

//for(int i = 0; i < tile.size(); ++i) {
//tile[i].setSize(_tile_size);
//tile[i].setup();
//}

}

void World::setXYOff(float xoff, float yoff) {
_xoff = xoff;
_yoff = yoff;
tile.clear();
//_r3 = ofRandom(0,1);
//_r1 = ofRandom(0,.75);
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
form();
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].update();
}
}

