#pragma once

#include "ofMain.h"

#include "Noise.h"
#include "SystemInfo.h"
#include "DistanceField.h"

#include "PlanetarySphere.h"
#include "Star.h"

#include "ofxRay.h"

class ofApp : public ofBaseApp {

public:

ofShader shader;
ofEasyCam cam;
ofPoint mouse;

Noise noise;
SystemInfo system;
DistanceField df;

Star star;
PlanetarySphere moon;
PlanetarySphere planet;
 
void draw(); 
void update();
void setup();

void mouseMoved(int x,int y);
void keyPressed(int key);
void keyReleased(int key);

void system_info();

void noise3d();

ofVec3f w_mouse;
ofVec3f w_mouse_end;
ofVec3f mouse_transmission;
ofRay mouse_ray;

//vector<float> test;
float test[1000];

float r1;

float n;

float w;
float h; 
 
bool shader_test;

bool mouse_reverse;
 
int keypress_i_;

bool _draw_sys_info;
int _draw_sys_count;
};
