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
void keyPressed(int key);
void keyReleased(int key);

float w = 0;
float h = 0;

ofCamera cam;
Player player;
//Plateau plateau;
World world;

ofLight light;

private:

};
