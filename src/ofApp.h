#pragma once
#include "ofMain.h"

#include "Planet.h"

class ofApp : public ofBaseApp {

public:

void setup();
void update();
void draw();
void keyPressed(int key);

float w = 0;
float h = 0;

Planet planet;

private:

};
