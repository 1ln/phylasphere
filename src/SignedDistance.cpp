#include "SignedDistance.h"

SignedDistance::SignedDistance() {
}

float SignedDistance::sphere(ofVec3f p,ofVec3f c,float r) {
ofVec3f n = p-c;
float l = n.length()-r;
return l;
}
