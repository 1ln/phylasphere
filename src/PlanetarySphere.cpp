#include "PlanetarySphere.h"

PlanetarySphere::PlanetarySphere() {

_radius = 100;
_p = ofVec3f(2500,0,0);
_orbital_center = ofVec3f(0,0,0);
_distance_from_center = 2500;
_scale = .00001;

} 

ofVec3f PlanetarySphere::g_Position() {
return _p;
}

void PlanetarySphere::radius(float r) { 

_radius = r;

}

void PlanetarySphere::orbiting(ofNode n) {
ico.setParent(n);
}

void PlanetarySphere::setup() {

_r = ofRandom(0,4000000);

_p = ofVec3f(  _distance_from_center,0,0);
ico.setPosition(_p);
ico.set(_radius,6);

orb.speed(.01);
orb.radius(_distance_from_center);

}

void PlanetarySphere::update() {
mesh = ico.getMesh();
vector<glm::vec3> & vert = mesh.getVertices();

for(unsigned int i = 0; i < vert.size(); ++i) {

    ofVec3f v = vert.at(i);
    v.normalize();

    _n = noise.fb3(v.x+_r*_scale,v.y+_r*_scale,v.z+_r*_scale);
    
    mesh.setVertex(i,vert.at(i)+(v*_n*35)+_p);    
    c.setHsb(_n*5+100,128,255);
    



    mesh.addColor(c);
}

     //orb.radius(_distance_from_center);
     //orb.speed(.000001);
     _p = orb.rotate(_orbital_center,_p) ;


}

//void PlanetarySphere::update() {
//}

void PlanetarySphere::draw() { 

mat.begin();
mesh.draw();
mat.end(); 

}
