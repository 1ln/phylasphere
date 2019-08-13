#include "Planet.h"

Planet::Planet() {

_r = 100;
_p = ofVec3f(0,0,0);
_orbital_center = ofVec3f(0,0,0);

} 

void Planet::position(ofVec3f p) {

_p = p;

}

void Planet::radius(float r) { 

_r = r;

}

void Planet::orbital_center(ofVec3f c) {
_orbital_center = c;
}

void Planet::setup() {

ico.set(_r,6);

ofVecf3 np = ofVec3f(ofRandom(0,1),ofRandom(0,1),ofRandom(0,1));
np.normalize() * (_r+250);
ico.setPosition(np);

mesh = ico.getMesh();
vector<glm::vec3> & vert = mesh.getVertices();

for(unsigned int i = 0; i < vert.size(); ++i) {

    ofVec3f v = vert.at(i);
    v.normalize();

    n = noise.octave3d(v.x,v.y,v.z);

    mesh.setVertex(i,vert.at(i)+(v*n*35));    

    c.setHsb(n*128,128,255);
    mesh.addColor(c);

}

}


void Planet::draw() { 
mesh.draw();
}

void Planet::update() {
position(orb.rotate(_orbital_center,_p);
}
