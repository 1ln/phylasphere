#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_map_width = 0;
_elevation = 0;
_tile_width = 0;
_total_tiles = 0;
_scale = 0;
_light = false;
_steps = 0;
} 

void World::init() {
    
    _r = ofRandom(0,4000000);
    _scale = 100;
    _map_width = 256;
    _tile_width = 8;
    _steps = _map_width / _tile_width;
    _total_tiles = _steps * _steps;
    //_ambient_lighting.setAmbientColor(ofColor(0,0,0));

    tileType(_r,_r);
    tile.push_back(Plateau(0,0,_elevation,_c,_light));

}

void World::scale(float s) {
_scale = s;
}

void World::tileType(float i,float j) {
_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
if(_n < .48) {
_elevation = 0;
_c.set(0,5,75*_n,155);
_light = false;
}
    if(_n > .479 && _n < .48) {
    _elevation = _n*_scale;
    _c.set(_n*15,_n*15,_n*15,255);
    _light = true;
}
    if(_n > .51) {
    _c.set(_n*15,_n*15,_n*15,255);
    _elevation =  _n * _scale;
    _light = false;     
}

}

void World::setup() {
 
ofSeedRandom(); 

init();

}

void World::remap() {

tile[0].addX(_tile_width);
for(int i = 0; i < _map_width; i+= _tile_width) {
    tileType((tile[0].X())+_r,i+_r);
    tile.insert(tile.begin(), Plateau((tile[0].X()),i,_elevation,_c,_light));
}

if(tile.size() >= _total_tiles) {
for(int i = 1; i <= _steps; ++i) {
tile.erase(tile.end()+i);
}
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

//ofDrawBox(tile[128+8].X(),tile[128+8].Y(),100,5,5,5);
//ofDrawBox(0,0,125,5,5,5);
//ofDrawBox(tile[tile.size()/2].X(),tile[tile.size()/2].Y(),100,5,5,5);
}

void World::update() {

//cout << tile.size() << endl;
remap();

if(tile.size() >= _total_tiles/2) {
world_plane.setPosition(tile[((_total_tiles-_steps)/2)].X(),tile[((_total_tiles-_steps)/2)].Y(),0);
_ambient_lighting.setPosition(tile[((_total_tiles-_steps)/2)].X(),tile[((_total_tiles-_steps)/2)].Y(),2500);
//_ambient_lighting.enable();

} else {
world_plane.setPosition(_map_width/2,_map_width/2,0);
_ambient_lighting.setPosition(_map_width/2,_map_width/2,2500);
}

for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].update();
}

}

