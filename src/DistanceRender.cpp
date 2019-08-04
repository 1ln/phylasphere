#include "DistanceRender.h"

DistanceRender::DistanceRender() {
}

fixed4 DistanceRender::ray_march(ofVec3f o,ofVec3f d) {
fixed4 col = fixed4(0,0,0,0);

float dt = 0;

for(int i = 0; i <= 64; ++i) {

float3 p = o + d * dt;
//float df =  map(p);
    if(d < 0.001) {
    col = fixed4(c.r,c.g,c.b,1);
    }

//dt += df;

}
return col;
}

//float DistanceRender::map(ofVec3f p) {

float DistanceRender::sphere(ofVec3f p, ofVec3f c,float r) {
return ofDistSquared(p,c) - r;
}

float DistanceRender::box(ofVec3f p,ofVec3f b) {
ofVec3f d = abs(p)-b;

ofVec3f k;
float l = k.length(max(d,0.0));
return l;
}
