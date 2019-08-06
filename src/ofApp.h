#pragma once

#include "ofMain.h"

#include "feature.h"
#include "Noise.h"
#include "Orbiter.h"
#include "Icosphere.h"
#include "Lightpanel.h"

#include "ofxRay.h"

class ofApp : public ofBaseApp {

public:

ofEasyCam cam;
ofPoint mouse;

ofShader shader;

Noise noise3;
Noise noise2;
Noise noise;

Orbiter orb;
Lightpanel lp;
Icosphere ico;

void draw(); 
void update();
void setup();

void mouseMoved(int x,int y);
void keyPressed(int key);
void keyReleased(int key);

void system_info();
void input_deactivate();
void tileType(float i,float j);
void map_init();

Feature _type;

vector <ofBoxPrimitive> boxes_layer1;
vector <ofBoxPrimitive> boxes_layer2;
ofBoxPrimitive box1;
ofBoxPrimitive box2;

vector <ofColor> box_color;

ofMaterial mat;

int _tile_width;

float _hue;

float _w;
float _h;

float _elevation;
float _elevation_reverse;
float _elevation_dist;

float _n;
float _n2;
float _n3;
float _scale;

float _cave_height;

float _r;
float _r2;
float _r3;

int _total_tiles;
ofColor _c;
ofColor _land;
float _steps;

ofTrueTypeFont font;
bool _draw_sys_info;
int _draw_sys_count;

float _map_width;
float _start_timer;
};
