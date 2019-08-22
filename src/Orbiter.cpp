#include "Orbiter.h"

Orbiter::Orbiter() {

orbital_radius_ = 0;
orbital_speed_ = 0.01;
orbital_progression_ = ofRandom(0,TWO_PI);
rotational_progression_ = 0;
rotational_speed_ = 0.001;
orbital_center_ = ofVec3f(0,0,0);
position_ = ofVec3f(0,0,0);

}

void Orbiter::orbitalSpeed(float s) {
orbital_speed_ = s;
}

void Orbiter::rotationalSpeed(float s) {
rotational_speed_ = s;
}

void Orbiter::orbitalCenter(ofVec3f c) {
orbital_center_ = c;
}

void Orbiter::position(ofVec3f p) {
position_ = p;
} 

void Orbiter::orbitalRadius(float r) { 
orbital_radius_ = r;
}

void Orbiter::setNode(ofNode n) {
n_ = n;
}

void Orbiter::rotateAxis(ofNode &n,ofVec3f axis) {
rotational_progression_ += rotational_speed_ * ofGetLastFrameTime();
n.rotateRad(rotational_progression_,axis);
}

void Orbiter::orbit(ofNode &n) {
rotational_progression_ += orbital_speed_ * ofGetLastFrameTime();
n.orbitRad(rotational_progression_,0,orbital_radius_,orbital_center_);
}

//ofVec3f Orbiter::orbit() {
//orbital_progression_ += orbital_speed_ * ofGetLastFrameTime();

//position_.z = orbital_center_.z + cos(orbital_progression_) * orbital_radius_;
//position_.x = orbital_center_.x + sin(orbital_progression_) * orbital_radius_;

//return position_;
//}
