#include "World.h"

World::World() {
_w = ofGetWidth();
_h = ofGetHeight();
_height = 0;
_buffer = 16;
_tile_size = 8;
//_type = "";
_scale = 0;
//f = 1;
} 

void World::form() {
_r =  ofRandom(0,.0001);
cout << _r << endl;
_r1 = ofRandom(0,.75);
_r2 = ofRandom(1,8);
_r3 = ofRandom(0,.45);
for(int i = -512; i <= 512; i+=_tile_size) {
    for(int j = -512 ; j <= 512; j+=_tile_size) {
    tileType(i,j,100);
    //_height = 100;
    tile.push_back(Plateau(i,j,_height,_c));
    }
}

}

float World::octaveNoise(int n,float x,float y,float p, float l) {
_result = 0;
_freq = 1;
_amp = 1;
for(int i = 0; i < n; i++) {
_result += ofNoise(x*_freq,y*_freq) * _amp;
_amp *= p;
_freq *= l;
}
return _result;
}

void World::tileType(float i,float j,float scale) {
_scale = scale;
//_n = octaveNoise(1,i*_r*100,j*_r*100,.25,2);
_n1 = octaveNoise(_r2,i*_r*100,j*_r*100,_r3,_r1);
//cout << _n << endl;
cout << "r : " << _r2 << endl;
//if(_n < .25) {
//_height = 0;
//_c.set(0,0,100,45);
//} else {
_c.set(0,_n1*100,0);
     //if(_n < .6) {
    //_height =  _n1 * _r2*550  ;
    //} else if ( _n < .85 ) {
    _height = _n1 * 100;
    //} else {
    //_height = _n * _r2*95;
//}
//}
}

void World::setup() {
ofSeedRandom();
//world_plane.setPosition(ofVec3f(0,0,0));
form();

for(int i = 0; i < tile.size(); ++i) {
tile[i].setSize(_tile_size);
tile[i].setup();
}
}

void World::rotateLeft() {
world_plane.rotateDeg(-45,0,0,1);
}

void World::rotateRight() {
world_plane.rotateDeg(45,0,0,1);
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


