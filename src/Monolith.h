#include "ofMain.h"

#include "Noise.h"

class Monolith {

public:

Monolith();

Noise noise1;
Noise noise0;
 
void draw(); 
void update();
void setup();

void position(ofVec3f p);

vector <ofBoxPrimitive> boxes_layer0;
vector <ofBoxPrimitive> boxes_layer1;
ofBoxPrimitive box0;
ofBoxPrimitive box1;

vector <ofColor> box_color;

ofMaterial mat;

int _step;
int _num;

float _elevation_l0;
float _elevation_l1;

float _n0;
float _n1;
float _scale;

float _r;
float _r2;

float _orbital_radius;

ofColor _c;
float _steps;

};
