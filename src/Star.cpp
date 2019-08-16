#include "Star.h"

Star::Star() {

_r = ofRandom(50,250);
_p = ofVec3f(0,0,0);


}

void Star::setup() {

light.setPosition(_p);

ico.set(_r,2);
ico.setPosition(_p);

//planet.orbital_center(_p);
//planet.setup();

}

void Star::draw() {

light.enable();
ico.drawWireframe();

//planet.draw();

}

void Star::update() {
//planet.update();
} 


