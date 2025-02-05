#include "PlanetarySystem.h"

PlanetarySystem::PlanetarySystem() {
process_type_  = 0;
num_moons_ = 0;
} 

void PlanetarySystem::systemType() {

if(process_type_ == 0) {

//num_moons_ = (int)ofRandom(1,25);

planet.setRadius(ofRandom(500,1000));
planet.setRotatingOnAxis(true);
planet.setHeight(0);

} else {

//num_moons_ = (int)ofRandom(450,750);

planet.setRadius(ofRandom(250,750));
planet.setRotatingOnAxis(true);
planet.setHeight(5);

}
}

void PlanetarySystem::moonType() {

if(process_type_ == 0) {

moon.setRadius(ofRandom(25,250));
moon.setHeight(ofRandom(0,10));
//moon.setPosition(ofRandom(2500,10000),0,0);

} else {

moon.setRadius(ofRandom(25,150));
moon.setHeight(ofRandom(0,10));
//moon.setPosition(ofRandom(1500,5000),0,0);

}
//moon.setRotatingOnAxis(true); 

}

void PlanetarySystem::setup() {

systemType();

planet.setup();

for(unsigned int i = 0; i < num_moons_; ++i) {

//moons.push_back(moon);



}




} 

void PlanetarySystem::draw() {

planet.draw();

//for(unsigned int i = 0; i < moons.size(); ++i) {
//moons.draw();
//}
} 

void PlanetarySystem::update() {

planet.update();

//for(unsigned int i = 0; i < moons.size(); ++i) {
//moons.update();
//}

}
