#include "Monolith.h"

void Monolith::setup() {

_elevation_l0 = 0;
_elevation_l1 = 0;

_r = ofRandom(0,4000000);   
_r2 = ofRandom(0,_r);

_scale = 150;
_num = 32;
_step= 2;

ofBackground(0);

mat.setShininess(100);
mat.setSpecularColor(ofColor(255,255,255,255));

    for( int i = p.x; i <= _num; i+= _step) {
        for( int j = p.z; j <= _num; j+= _step) {  
               
            _n0 =  noise0.octave2d((i+_r)*_scale*0.00001,(j+_r)*_scale*0.00001);
            _n1 =  noise1.octave2d((i+_r2)*_scale*0.00001,(j+_r2)*_scale*0.00001);
        
            _elevation_l0 = _n0*(_scale);
            _elevation_l1 = _n1*(_scale);
            _c.setHsb(0,128,128,.5);
        
            box_color.push_back(_c);
            box0.set(_step,_elevation_l0,_step);
            box1.set(_step,-_elevation_l1,_step);
            box0.setPosition(i,_elevation_l0/2,j);
            box1.setPosition(i,-_elevation_l1/2,j);
            boxes_layer0.push_back(box0);
            boxes_layer1.push_back(box1);

        }
    }

}

void Monolith::draw() {

glEnable(GL_DEPTH_TEST);

    mat.begin();

    for(unsigned int i = 0; i < boxes_layer0.size(); ++i) {
        ofSetColor(box_color[i]);
        boxes_layer0[i].draw();
    }
     
    for(unsigned int i = 0; i < boxes_layer1.size(); ++i) {
        ofSetColor(box_color[i]);
        boxes_layer1[i].draw();
    }

    mat.end();

}

void Monolith::update() {
}

void Monolith::position(ofVec3f p) {

_p = p;

}




