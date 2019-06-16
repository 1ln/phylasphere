#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_tiles = 450;
_height = 0;
_type = "";
} 

void World::form() {
for(int i = -_w/2; i < _w; i+=100) {
    for(int j = -_h/2; j < _h; j+=100) {
    tile.push_back(Plateau(i,j,tileHeight(i,j)*100,_type));
    }
}

} 

float World::tileHeight(float i,float j) {
//_height = ofNoise(i*.21,j*.21);
_height = ofRandom(0,1);
//_height = 10;
//cout << _height << endl;
return _height;
}

void World::setup() {

form();

for(int i = 0; i < tile.size(); ++i) {
tile[i].setup();
}
}


void World::draw() {
//cout << tile.size() << endl;
for(unsigned int i = 0; i < tile.size(); ++i) {
tile[i].draw();
//cout << i << endl;
//ofColor(255,0,0,255);
}
}

void World::update() {
}


