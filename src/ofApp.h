#pragma once

#include "ofMain.h"

#include "Planet.h"
#include "Star.h"

#include "ofxRay.h"

class ofApp : public ofBaseApp {

public:

ofEasyCam cam;
ofPoint mouse;

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


ofVec3f w_mouse;
ofVec3f w_mouse_end;
ofVec3f mouse_transmission;
ofRay mouse_ray;

float _x;
float _y;

//float _r;
//float _r2;
//float _r3;

ofTrueTypeFont font;
bool _draw_sys_info;
int _draw_sys_count;
};
