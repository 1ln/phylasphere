#include "SignedDistance.h"

SignedDistance::SignedDistance() {
}

float SignedDistance::sphere(ofVec3f p,ofVec3f c,float r) {
//cout << p << endl;
//cout << c << endl;
//cout << r << endl;
ofVec3f n ;
return   p.distance(c)-r;
}
