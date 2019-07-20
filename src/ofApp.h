#pragma once
#include "ofMain.h"
 
#include "Player.h" 
#include "Plateau.h"
#include "World.h"

class ofApp : public ofBaseApp {

public:

void setup();
void update();
void draw();
void keyReleased(int key);
void keyPressed(int key);
void mouseMoved(int x,int y);

float w = 0;
float h = 0;
 
ofCamera cam;
//Player player;
World world;

//ofLight light;
//ofLight light2;

ofPoint mouse;
private:

float _mloc_x;
float _mloc_y;

};
