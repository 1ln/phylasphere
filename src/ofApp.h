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

Noise noise1;
Noise noise0;

Orbiter orb0;
Orbiter orb1;
Orbiter orb2;

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

vector <Orbiter> orbs;

vector <ofBoxPrimitive> boxes_layer0;
vector <ofBoxPrimitive> boxes_layer1;
ofBoxPrimitive box0;
ofBoxPrimitive box1;

vector <ofColor> box_color;

ofMaterial mat;

int _tile_width;

float _hue;

float _w;
float _h;

float _elevation_l0;
float _elevation_l1;

float _n0;
float _n1;
float _scale;

float _r;
float _r2;
float _r3;

int _total_tiles;
ofColor _c;
float _steps;

ofTrueTypeFont font;
bool _draw_sys_info;
int _draw_sys_count;

float _map_width;
float _start_timer;
};
