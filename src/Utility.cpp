#include "Utility.h"

Utility::Utility() {
_x = 0;
_y = 0;
_theta = 0;
_distance = 0;
} 

float Utility::randAngleSqrt(float radius) {
_theta = glm::sqrt(ofRandom(0,1)) * radius;
return _theta; 
}

float Utility::randAngle() {
_theta = 2*PI*ofRandom(0,1);
return _theta;
}

float Utility::annulusDistance(float inner_radius,float outer_radius) {
_distance = glm::sqrt(ofRandom(0,1) * (((outer_radius * 2) - (inner_radius * 2)) + inner_radius *2));
return _distance;
}
