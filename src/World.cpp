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
_hue = 0;
_steps = 0;
_x_width = 0;
_spotlight_x = 0;
_spotlight_y = 10000;
} 

void World::init() {
    
    _r = ofRandom(0,4000000);
    _scale = 100;
    _map_width = 256;
    _tile_width = 4;
    _steps = _map_width / _tile_width;
    _total_tiles = _steps * _steps;
    light_col.setHsb(255,0,255);
    light.setDiffuseColor(light_col);
    light.setSpotlight();
    light.setSpotConcentration(10);
    light.setSpotlightCutOff(12);

}

void World::scale(float s) {

_scale = s;

}

void World::sideColor() {

//for(int i = 0; i < 6; ++i) {
box.setSideColor(0,_c);
box.setSideColor(2,_c);
box.setSideColor(4,_c);

//}

}

void World::tileType(float i,float j) {

_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
_n1 = noise2.octave(4,i*25*.00001,j*25*.00001,.5,2);

if(_n < .5) {
    _elevation = 10;
    _c.set(5,35,255);
} else {
    _c.set(_n*75,_n*75,_n*75,255);
    _elevation =  _n * _scale;

if(_n1 < .98) {
_c.set(255,0,0);
}
}
}


void World::setup() {
 
ofSeedRandom(); 

init();

}

void World::remap() {

if(boxes.size() >= _total_tiles) {
boxes.erase(boxes.begin(),boxes.begin()+_steps);
}

_x_width += _tile_width;

for(int i = 0; i < _map_width-1; i+= _tile_width) {

    tileType(_x_width+_r,i+_r);
    box.set(_tile_width,_tile_width,_elevation);
    box.setPosition(_x_width,i,0);
    sideColor();
    





    boxes.push_back(box);

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

ofEnableLighting();
//ofSetSmoothLighting(true);

for(unsigned int i = 0; i < boxes.size(); ++i) {

boxes[i].draw();
}

light.enable();
light.draw();
}

void World::update() {

remap();

if(boxes.size() >= _total_tiles) {
world_plane.setPosition(boxes[((_total_tiles-_steps)/2)].getX(),boxes[((_total_tiles-_steps)/2)].getY(),0);
light.setPosition(boxes[((_total_tiles-_steps)/2)].getX(),boxes[((_total_tiles-_steps)/2)].getY(),125);
} else {
world_plane.setPosition(_map_width/2,_map_width/2,0);
}

light.lookAt(ofVec3f(ofMap(ofNoise(_spotlight_x),0,1,_x_width-_map_width,_x_width),ofMap(ofNoise(_spotlight_y),0,1,0,_map_width),100));
_spotlight_x += 0.005;
_spotlight_y += 0.005;


}

