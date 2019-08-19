#include "PlanetarySphere.h"

PlanetarySphere::PlanetarySphere() {

_r = 100;
_p = ofVec3f(0,0,0);
_orbital_center = ofVec3f(0,0,0);
_distance_from_center = 0;
 
} 

ofVec3f PlanetarySphere::g_Position() {
return _p;
}

void PlanetarySphere::radius(float r) { 

_r = r;

}

void PlanetarySphere::orbiting(ofNode n) {
ico.setParent(n);
}

void PlanetarySphere::setup() {

_p = ofVec3f(  _distance_from_center,0,0);
ico.setPosition(_p);
ico.set(_r,6);
}

void PlanetarySphere::update() {
mesh = ico.getMesh();
vector<glm::vec3> & vert = mesh.getVertices();

for(unsigned int i = 0; i < vert.size(); ++i) {

    ofVec3f v = vert.at(i);
    v.normalize();

    _n = noise.fb3(v.x,v.y,v.z);

    mesh.setVertex(i,vert.at(i)+(v*_n*35)+_p);    

    c.setHsb(_n*128,128,255);
    mesh.addColor(c);
}

     //orb.radius(_distance_from_center);
     //orb.speed(.0001);
     //_p = orb.rotate(_orbital_center,_p) ;


}

void PlanetarySphere::draw() { 

mat.begin();
mesh.draw();
mat.end(); 

}
