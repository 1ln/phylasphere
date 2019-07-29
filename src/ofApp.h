#pragma once

#include "ofMain.h"

#include "feature.h"
#include "Noise.h"
#include "Orbiter.h"

#include "ofxBullet.h"

class ofApp : public ofBaseApp {

public:

ofEasyCam cam;
ofPoint mouse;

Orbiter orb;
Noise noise;

void draw(); 
void update();
void setup();

//void mouseMoved(int x,int y);
void keyPressed(int key);
void keyReleased(int key);

void input_deactivate();
void tileType(float i,float j);
void map_init();

Feature _type;

int _tile_width;

float _hue;

float _w;
float _h;

float _elevation;
float _n;
float _n1;
float _scale;
float _r;

int _total_tiles;
ofColor _c;
float _steps;
//ofLight _spotlight;
//ofLight _light;
//float _spotlight_radius;
//float _box_radius;
//ofColor _light_col;
//float _spotlight_x;
//float _spotlight_y; 

ofxBulletWorldRigid world;

vector <ofColor> _tile_box_color;
vector <shared_ptr <ofxBulletRigidBody>> _tile_boxes;
vector <shared_ptr <ofxBulletRigidBody>> _boxes;

float _map_width;
float _start_timer;
};
