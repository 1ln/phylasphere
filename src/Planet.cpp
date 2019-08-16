#include "Planet.h"

Planet::Planet() {

_r = 100;
_p = ofVec3f(0,0,0);
_orbital_center = ofVec3f(0,0,0);

} 

ofVec3f Planet::g_Position() {

return _p;
}

void Planet::radius(float r) { 

_r = r;

}

void Planet::orbital_center(ofVec3f c) {
_orbital_center = c;
}

void Planet::orbiting(ofNode n) {
//ico.setParent(n);
}

void Planet::setup() {


//np = ofVec3f(ofRandom(0,1),ofRandom(0,1),ofRandom(0,1));
//np = np.normalize() * (2250);
_p = ofVec3f(2000,0,0);
ico.setPosition(_p);
ico.set(_r,6);
}

void Planet::update() {
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

     orb.radius(2000);
     orb.speed(.00001);
     _p = orb.rotate(_orbital_center,_p) ;


}

void Planet::draw() { 
mesh.draw();
}
