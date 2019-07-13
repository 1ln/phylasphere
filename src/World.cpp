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
_x_width = 0;
} 

void World::init() {
    
    _r = ofRandom(0,4000000);
    _scale = 100;
    _map_width = 256;
    _tile_width = 4;
    _steps = _map_width / _tile_width;
    _total_tiles = _steps * _steps;
    //_ambient_lighting.setAmbientColor(ofColor(0,0,0));
    //light.setAttenuation(0.001,0.0001,0.001);
    //material.setEmissiveColor(ofColor(255,255,255));

}

void World::scale(float s) {

_scale = s;

}

void World::sideColor() {

for(int i = 0; i < 6; ++i) {
box.setSideColor(i,_c);
}

}

void World::tileType(float i,float j) {
_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
if(_n < .48) {

_elevation = 10;
//_c.set(0,5,75*_n,255);
//material.setDiffuseColor(_c);

_light = false;
}
    if(_n > .48 && _n < .49) {
    _elevation = _n*_scale;
    //_c.set(_n*15,_n*15,_n*15,255);
    _light = true;
}
    if(_n > .49) {
    //_c.set(_n*15,_n*15,_n*15,255);
    _elevation =  _n * _scale;
    _light = false;     
}

}

void World::setup() {
 
ofSeedRandom(); 

init();

}

void World::remap() {
if(tile.size() >= _total_tiles) {
materials.erase(materials.begin(),materials.begin()+_steps);
tile.erase(tile.begin(),tile.begin()+_steps);
}

if(lights.size() >= 35) {
//lights.erase(lights.begin(),lights.begin()+1);
}

_x_width += _tile_width;

for(int i = 0; i < _map_width-1; i+= _tile_width) {

    tileType(_x_width+_r,i+_r);
    
    //if(_light == true) {
    _c.set(_n*255,0,0);
    //}

    material.setDiffuseColor(_c);
    //} else {
    //sideColor();
//}

    materials.push_back(material);
  
    box.set(_tile_width,_tile_width,_elevation);
    box.setPosition(_x_width,i,0);
    //sideColor();
    //material.end();
    tile.push_back(box);

    //if(_light == true) {
    //light.setup();
    //light.setPointLight();
    //light.setPosition(_x_width,i,_elevation+5);
    //light.setAttenuation(0.0001,0.001,0.001);
    //light.setParent(box);
    //light.setup();
    //light.enable();
    //lights.push_back(light);
    //}

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

//material.begin();
for(unsigned int i = 0; i < tile.size(); ++i) {

//material.begin();
materials[i].begin();
tile[i].draw();
materials[i].end();
//material.end();
}
//material.end();

}

void World::lights_enable() {
for(unsigned int i = 0; i < lights.size(); ++i) {
//lights[i].enable();
//lights[i].draw();

}

//ofDrawBox(tile[128+8].X(),tile[128+8].Y(),100,5,5,5);
//ofDrawBox(0,0,125,5,5,5);
//ofDrawBox(tile[tile.size()/2].X(),tile[tile.size()/2].Y(),100,5,5,5);
}

void World::update() {

//cout << tile.size() << endl;
remap();

if(tile.size() >= _total_tiles) {
world_plane.setPosition(tile[((_total_tiles-_steps)/2)].getX(),tile[((_total_tiles-_steps)/2)].getY(),0);
light.setPosition(tile[((_total_tiles-_steps)/2)].getX(),tile[((_total_tiles-_steps)/2)].getY(),_elevation+25);
light.enable();
light.draw();
} else {
world_plane.setPosition(_map_width/2,_map_width/2,0);
//_ambient_lighting.setPosition(_map_width/2,_map_width/2,2500);
}

//for(unsigned int i = 0; i < tile.size(); ++i) {
//tile[i].update();
//}

}

