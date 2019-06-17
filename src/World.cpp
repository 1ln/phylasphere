#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_tiles = 450;
_height = 0;
_type = "";
_scale = 0.00563;
} 

void World::form() {
for(int i = -128; i <= 128; i+=16) {
    for(int j = -128; j <= 128; j+=16) {
    tile.push_back(Plateau(i,j,tileHeight(i,j),_type));
    }
}

} 

float World::tileHeight(float i,float j) {
_n = ofNoise(i*_scale,j*_scale);

if(_n < 0.20) {
_height = 55;
} else if (_n < 0.40) {
_height = 25;
} else {
_height = 0;
}
//_height = ofRandom(0,1);
//_height = 0;
cout << _height << endl;
return _height;
}

void World::setup() {
world.setPosition((_w/2),(_h/2),0);
form();

for(int i = 0; i < tile.size(); ++i) {
tile[i].setup();
}
}


void World::draw() {
//cout << tile.size() << endl;
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].draw();
//ofTranslate(_w/2,_h/2,0);
//cout << i << endl;
//ofColor(255,0,0,255);
}
}

void World::update() {
}


