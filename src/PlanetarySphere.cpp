#include "PlanetarySphere.h"

PlanetarySphere::PlanetarySphere() {

radius_ = 100;
position_ = ofVec3f(0,0,0);
orbital_center_ = ofVec3f(0,0,0);
distance_from_center_ = 0;
scale_ = .00001;
rotate_on_axis_ = false;
orbiting_ = false;
height_ = 0;

} 

void PlanetarySphere::setPosition(ofVec3f p) {
position_ = p;
}

void PlanetarySphere::setRadius(float r) { 
radius_ = r;
}

void PlanetarySphere::setHeight(float h) {
height_ = h;
} 

void PlanetarySphere::setOrbiting(bool orbiting) {
orbiting_ = orbiting;
}

void PlanetarySphere::setRotatingOnAxis(bool rotating) {
rotate_on_axis_ = rotating;
}

void PlanetarySphere::setup() {
//shader.load("render.vert","render.frag");

}

void PlanetarySphere::update() { 
} 

void PlanetarySphere::draw() {

_r = ofRandom(0,4000000);

position_ = ofVec3f(distance_from_center_,0,0);
ico.setPosition(position_);
ico.set(radius_,6);

mesh = ico.getMesh();
vector<glm::vec3> & vert = mesh.getVertices();

for(unsigned int i = 0; i < vert.size(); ++i) {

    ofVec3f v = vert.at(i);
    v.normalize();

    //_n = noise.fb3(v.x+_r*scale_,v.y+_r*scale_,v.z+_r*scale_);
    _n = noise.fb3(v +_r*scale_);
    
    //shader.setUniform2f("u_resolution",ofGetWidth(),ofGetHeight());   
    //shader.setUniform1f("u_noise",_n);
   
    mesh.setVertex(i,vert.at(i)+(v*_n*height_));    
    c.setHsb(_n*25+25,128,255);
    mesh.addColor(c);
}
    primitive.getMesh().append(mesh);     
//}

//void PlanetarySphere::update() {

if(rotate_on_axis_ == true) {
//orb.rotateAxis(primitive,ofVec3f(0,1,0));
}

if(orbiting_ == true) { 
//orb.orbit(primitive);
}

//}

//void PlanetarySphere::draw() { 

mat.begin(); 
primitive.draw();
mat.end(); 

//shader.begin();


//ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//shader.end();



}
