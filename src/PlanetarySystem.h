#ifndef _PlanetarySystem
#define _PlanetarySystem

#include "ofMain.h"
#include "PlanetarySphere.h"


class PlanetarySystem {

public:

PlanetarySystem();

PlanetarySphere planet;
PlanetarySphere moon;

void systemType();
void moonType();

void setup();
void update();
void draw();

private:

int process_type_;
int num_moons_;




};

#endif
