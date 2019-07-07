#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_height = 0;
_buffer = 16;
_tile_size = 16;
_scale = 0;
_xoff = 0;
_yoff = 0;
_light = false;
_i = 0;
_k = 0;
} 

void World::form() {

for(int i = 128; i > -128; i-=_tile_size) {
    for(int j = -128; j < 128; j+=_tile_size) {
    cout << i << "," << j << endl;
    tileType(i+_r,j+_r);
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
    if(_n > .48 && _n < .49) {
    _height = _n*_scale;
    _c.set(_n*255,_n*255,_n*255,255);
    _light = false;
}
    if(_n > .51) {
    _c.set(_n*255,_n*255,_n*255,255);
    _height =  _n * _scale;
    _light = false;     
}

}

void World::setup() {
 
ofSeedRandom(); 

//world_plane.setPosition(0,0,0);
scale(100);
_r = ofRandom(0,4000000) ;
//_level = ofRandom(.4,.85);

form();
world_plane.setPosition(tile[128+8].X(),tile[128+8].Y(),0);

for(int i = 0; i < tile.size(); ++i) {
//tile[i].setSize(_tile_size);
//tile[i].setup();
}

}

void World::offXY(float xoff, float yoff) {
//_xoff = xoff;
//_yoff = yoff;

cout << "x " << tile[tile.size()/2].X() << endl;
cout << "y " << tile[tile.size()/2].Y() << endl;

//cout << "x_0 " << tile[0].X() << endl;
//cout << "y_0 " << tile[0].Y() << endl;
    for(int j = 0; j < 255; j+=16) {
    tileType((tile[0].X())+_r,(-127)+j+_r);
    tile.insert(tile.begin(), Plateau((tile[0].X()),(-127)+j,_height,_c,_light));
    //cout << tile[0].X() << endl;
    //cout << tile[0].Y() << endl;
}
tile[0].addX(16);

for(int i = 1; i <= 16; ++i) {
tile.erase(tile.end()+i);
}

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

ofDrawBox(tile[128+8].X(),tile[128+8].Y(),100,5,5,5);
//ofDrawBox(0,0,125,5,5,5);
//ofDrawBox(tile[tile.size()/2].X(),tile[tile.size()/2].Y(),100,5,5,5);
}

void World::update() {

//cout << tile.size() << endl;
//form();

world_plane.setPosition(tile[128+8].X(),tile[128+8].Y(),0);
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].update();
}
//world_plane.setPosition(tile[0].X()+(-128),tile[0].Y()+(-128),0);

}

