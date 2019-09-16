#pragma once

#include "ofMain.h"

#include "Noise.h"
#include "PlanetarySphere.h"
#include "Star.h"

#include "ofxRay.h"

class ofApp : public ofBaseApp {

public:

ofShader shader;
ofEasyCam cam;
ofPoint mouse;

Noise noise;

Star star;
PlanetarySphere moon;
PlanetarySphere planet;
 
void draw(); 
void update();
void setup();

void mouseMoved(int x,int y);
void keyPressed(int key);

void system_info();

ofVec3f w_mouse;
ofVec3f w_mouse_end;
ofVec3f mouse_transmission;
ofRay mouse_ray;

float r1;

float w;
float h; 
 
bool shader_test;

bool mouse_reverse;

ofTrueTypeFont font;
bool _draw_sys_info;
int _draw_sys_count;
};
