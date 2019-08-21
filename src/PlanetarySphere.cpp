#include "PlanetarySphere.h"

PlanetarySphere::PlanetarySphere() {

_radius = 100;
position_ = ofVec3f(0,0,0);
_orbital_center = ofVec3f(0,0,0);
_distance_from_center = 0;
_scale = .00001;
//rotate_around_  = false;
//rotate_on_axis_ = false;
//vertex_displace_ = false;

} 

void PlanetarySphere::setPosition(ofVec3f p) {
position_ = p;
}

void PlanetarySphere::radius(float r) { 

_radius = r;

}

void PlanetarySphere::setOrbiting(bool orbiting) {
orbiting_ = orbiting;

}

void PlanetarySphere::orbiting(ofNode n) {
ico.setParent(n);
}

void PlanetarySphere::setup() {

_r = ofRandom(0,4000000);

position_ = ofVec3f(  _distance_from_center,0,0);
ico.setPosition(position_);
ico.set(_radius,6);

orb.position(position_);

orb.orbitalSpeed(.01);
orb.orbitalCenter(ofVec3f(0,0,0));
//orb.orbitalRadius();

orb.rotationalSpeed(0.0001);
//orb.setNode(ico);

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
    //orb.rotateAxis(primitive);
    //_p = orb.rotate(_orbital_center,_p) ;
}

void PlanetarySphere::update() {
//orb.rotateAxis(primitive,ofVec3f(0,1,0));
if(orbiting_ == true) { 
orb.orbit(primitive);
}

}

void PlanetarySphere::draw() { 

mat.begin();
primitive.draw();
mat.end(); 

}
