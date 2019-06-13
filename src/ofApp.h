#pragma once
#include "ofMain.h"

#include "Plateau.h"

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
Plateau plateau;

ofLight light;

private:

};
