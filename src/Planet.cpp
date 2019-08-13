#include "Planet.h"

Planet::Planet() {
_r = 100;
} 

void Planet::position(ofVec3f p) {
_p = p;
}

void Planet::radius(float r) { 
_r = r;
}

void Planet::setup() {

ico.set(_r,6);
ico.setPosition(_p);

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

}
