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
_spotlight_radius = 12;
_box_radius = 0;
_x_width = 0;
_spotlight_x = 0;
_spotlight_y = 10000;
_input = false;
} 

void World::init() {
    
    _r = ofRandom(0,4000000);
    _scale = 100;
    _map_width = 256;
    _tile_width = 4;
    _box_radius = _tile_width/2;
    _steps = _map_width / _tile_width;
    _total_tiles = _steps * _steps;
    _light_col.setHsb(255,0,255);
    _spotlight.setDiffuseColor(_light_col);
    _spotlight.setSpotlight();
    _spotlight.setSpotConcentration(10);
    _spotlight.setSpotlightCutOff(_spotlight_radius);

}

void World::scale(float s) {

_scale = s;

}

void World::sideColor() {

//for(int i = 0; i < 6; ++i) {
//box.setSideColor(0,_c); 
//box.setSideColor(2,_c);
//box.setSideColor(4,_c);

//}

}

void World::tileType(float i,float j) {

_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
_n1 = noise2.octave(8,i*_scale*.0001,j*_scale*.0001,.05,4);
if(_n < .5) {
    _type = WATER;
    _elevation = 10;
    _c.set(5,35,255);
} else {
    _type = LAND;
    _c.set(_n*75,_n*75,_n*75,255);
    _elevation =  _n * _scale;

    if(_n1 > .95) {
    _type = TEST;
   //_c.set(0,255,0);
    }
}
}


void World::setup() {
 
ofSeedRandom(); 

init();

}

void World::remap() {

if(_tile_boxes.size() >= _total_tiles) {
_tile_boxes.erase(_tile_boxes.begin(),_tile_boxes.begin()+_steps);
}

if(_boxes.size() > 0) { 
for(unsigned int i = 0; i < _boxes.size(); ++i) {
if(_boxes[i].getX() < (_x_width-_map_width)) {
_boxes.erase(_boxes.begin() + i,_boxes.begin()+i+1 );
cout << i << endl;
}
}
}


_x_width += _tile_width;

for(int i = 0; i < _map_width-1; i+= _tile_width) {

    tileType(_x_width+_r,i+_r);
    _tile_box.set(_tile_width,_tile_width,_elevation);
    _tile_box.setPosition(_x_width,i,0);

    
    _tile_box.setSideColor(0,_c);
    _tile_box.setSideColor(2,_c);
    _tile_box.setSideColor(4,_c);
    
    _tile_boxes.push_back(_tile_box);
    
    if(_type == TEST) {
    _box.set(_tile_width,_tile_width,10);
    _box.setPosition(_x_width,i,_elevation);
    
    _box.setSideColor(0,ofColor(255,0,0));
    _box.setSideColor(2,ofColor(255,0,0));
    _box.setSideColor(4,ofColor(255,0,0));
    
    _boxes.push_back(_box);
    }

}

}

void World::rotate45() {
world_plane.rotateDeg(-45,0,0,1);
}


void World::input_activated() {
_input = true;
_start_timer = ofGetElapsedTimeMillis();
}

void World::input_deactivate() {
if((ofGetElapsedTimeMillis() - _start_timer) > 1000) {
_input = false;
}
}

void World::draw() {

ofEnableLighting();
ofSetSmoothLighting(true);

for(unsigned int i = 0; i < _tile_boxes.size(); ++i) {
_tile_boxes[i].draw();
}

for(unsigned int i = 0; i < _boxes.size(); ++i) { 
_boxes[i].draw();
}

_spotlight.enable();
_spotlight.draw();
}

void World::update() {

remap();

if(_tile_boxes.size() >= _total_tiles) {
world_plane.setPosition(_tile_boxes[((_total_tiles-_steps)/2)].getX(),_tile_boxes[((_total_tiles-_steps)/2)].getY(),0);
_spotlight.setPosition(_tile_boxes[((_total_tiles-_steps)/2)].getX(),_tile_boxes[((_total_tiles-_steps)/2)].getY(),125);
} else {
world_plane.setPosition(_map_width/2,_map_width/2,0);
}

_spotlight.lookAt(ofVec3f(ofMap(ofNoise(_spotlight_x),0,1,_x_width-_map_width,_x_width),ofMap(ofNoise(_spotlight_y),0,1,0,_map_width),100));

_spotlight_x += 0.005;
_spotlight_y += 0.005;

input_deactivate();

for(unsigned int i = 0; i < _boxes.size(); ++i) { 
    if(_input == true) {
        if(_spotlight_radius*2 > ofDistSquared(_spotlight.getX(),_spotlight.getY(),_boxes[i].getX(),_boxes[i].getY())) {
 //       cout << _boxes[i].getX() << endl;
        
    //if(_input == true) {
    //cout << _boxes[i].getX() << endl;         
    _boxes[i].setSideColor(0,ofColor(255,255,255));
    _boxes[i].setSideColor(2,ofColor(255,255,255));
    _boxes[i].setSideColor(4,ofColor(255,255,255));

        } 
    }
   
   

}

}

