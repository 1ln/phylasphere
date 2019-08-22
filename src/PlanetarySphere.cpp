#include "PlanetarySphere.h"

PlanetarySphere::PlanetarySphere() {

radius_ = 100;
position_ = ofVec3f(0,0,0);
orbital_center_ = ofVec3f(0,0,0);
distance_from_center_ = 0;
scale_ = .00001;
rotate_on_axis_ = false;
orbiting_ = false;

} 

void PlanetarySphere::setPosition(ofVec3f p) {
position_ = p;
}

void PlanetarySphere::setRadius(float r) { 
_radius = r;
}

void PlanetarySphere::setOrbiting(bool orbiting) {
orbiting_ = orbiting;
}

void PlanetarySphere::setOrbitalCenter(ofVec3f c) {
orbital_center_ = c;
}

void PlanetarySphere::setDistanceFromCenter(ofVec3f d) {
distance_from_center_ = d;
}

void PlanetarySphere::setRotatingOnAxis(bool rotating) {
rotate_on_axis_ = rotating;
}

void PlanetarySphere::setup() {

_r = ofRandom(0,4000000);

position_ = ofVec3f(  _distance_from_center,0,0);
ico.setPosition(position_);
ico.set(_radius,6);

mesh = ico.getMesh();
vector<glm::vec3> & vert = mesh.getVertices();

for(unsigned int i = 0; i < vert.size(); ++i) {

    ofVec3f v = vert.at(i);
    v.normalize();

    _n = noise.fb3(v.x+_r*_scale,v.y+_r*_scale,v.z+_r*_scale);
    
    mesh.setVertex(i,vert.at(i)+(v*_n*15));    
    c.setHsb(_n*25+25,128,255);
    mesh.addColor(c);
}
    primitive.getMesh().append(mesh);     
}

void PlanetarySphere::update() {

if(rotate_on_axis == true) {
orb.rotateAxis(primitive,ofVec3f(0,1,0));
}

if(orbiting_ == true) { 
orb.orbit(primitive);
}

}

void PlanetarySphere::draw() { 

mat.begin();
primitive.draw();
mat.end(); 

}
