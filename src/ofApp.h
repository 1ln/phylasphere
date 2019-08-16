#pragma once

#include "ofMain.h"

//#include "feature.h"
//#include "Noise.h"
#include "Planet.h"
#include "Star.h"

#include "ofxRay.h"

class ofApp : public ofBaseApp {

public:

ofEasyCam cam;
ofPoint mouse;
//Noise noise1;
//Noise noise0;

Star star;
Planet planet;
 
void draw(); 
void update();
void setup();

void mouseMoved(int x,int y);
void keyPressed(int key);
void keyReleased(int key);

void system_info();
void input_deactivate();
void map_init();

//vector <ofBoxPrimitive> boxes_layer0;
//vector <ofBoxPrimitive> boxes_layer1;
//ofBoxPrimitive box0;
//ofBoxPrimitive box1;

//vector <ofColor> box_color;

ofVec3f center;

//int _tile_width;

//float _hue;

float _x;
float _y;

//float _elevation_l0;
//float _elevation_l1;

//float _n0;
//float _n1;
//float _scale;

//float _r;
//float _r2;
//float _r3;

//int _total_tiles;
//ofColor _c;
//float _steps;

ofTrueTypeFont font;
bool _draw_sys_info;
int _draw_sys_count;

//float _map_width;
//float _start_timer;
};
