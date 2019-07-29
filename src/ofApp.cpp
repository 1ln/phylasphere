#include "ofApp.h"

void ofApp::setup() {

_w = ofGetWidth();
_h = ofGetHeight();

_elevation = 0;
//_spotlight_x = 0;
//_spotlight_y = 10000;
    
_r = ofRandom(0,4000000);
_scale = ofRandom(100,195);
_map_width = 256;
_tile_width = 4;
_steps = _map_width / _tile_width;
_total_tiles = _steps * _steps;

//_light_col.setHsb(255,0,255);

//_light.setDiffuseColor(_light_col);
//_spotlight.setSpotlight();

//_light.setDirectional();
//_light.setPosition(ofVec3f(0,500,0));

//_spotlight.setSpotConcentration(75);
//_spotlight.setSpotlightCutOff(12);

ofBackground(155);

ofSeedRandom();

cam.setPosition(ofVec3f(250,250,250));
cam.lookAt(ofVec3f(0,0,0));

cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_LEFT);
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_TRANSLATE_Z,OF_MOUSE_BUTTON_RIGHT);
cam.addInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_RIGHT);

orb.setup();

world.setup();
world.setGravity(ofVec3f(0,-.9,0));
world.enableGrabbing();
world.setCamera(&cam);

map_init();
}

void ofApp::tileType(float i,float j) {

_n = noise.octave(8,i*_scale*.00001,j*_scale*.00001,.5,2);
_n1 = noise.octave(8,i*_scale*.0001,j*_scale*.0001,.05,4);

    if(_n < .5) {
        _type = WATER;
        _elevation = (_n*_scale)-5;
        _c.setHsb(145,195,_n*255);
    } else {
        _type = LAND;
        _c.setHsb(0,0,45);
        _elevation =  _n * _scale;

        if(_n1 > .95) {
            _type = TEST;
        } 
    }
}

void ofApp::keyPressed(int key) {

    if(key == 'i') {
    //string fps = "FPS: " + ofToString(ofGetFrameRate(),2);
    //ofDrawBitmapString(fps,10,10);
    }

    if(key == 'r') {
    _tile_boxes.clear();
    _tile_box_color.clear();
    _boxes.clear();
    //map_init();
    }

}

void ofApp::keyReleased(int key) {

    if(key == 'r') {
         _r = ofRandom(4000000);
         ofSeedRandom();
         map_init();
    }
} 

//void ofApp::input_deactivate() {

    //if((ofGetElapsedTimeMillis() - _start_timer) > 1000) {
        //_input = false;
    //}
//}

//void ofApp::mouseMoved(int x,int y) {

//mouse.x = _x;
//mouse.y = _y;

//}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST); 
ofSetSmoothLighting(true);
//orb.draw();
cam.begin();

orb.draw();
//_light.enable();

    for(unsigned int i = 0; i < _tile_boxes.size(); ++i) {
        ofSetColor(_tile_box_color[i]);
        _tile_boxes[i]->draw();
    }

    for(unsigned int i = 0; i < _boxes.size(); ++i) {
        ofSetColor(ofColor(100,100,100));
        _boxes[i]->draw();
    }
    

cam.end();
}

void ofApp::update() {
world.update();
orb.update();
}

void ofApp::map_init() {

    for( int i = -(_map_width/2); i <= _map_width/2; i+= _tile_width) {
        for( int j = -(_map_width/2); j <= _map_width/2; j+= _tile_width) {  
        tileType(i+_r,j+_r);
 
        _tile_box_color.push_back(_c);
    
        shared_ptr <ofxBulletBox> _tile_box(new ofxBulletBox());
        _tile_box->create(world.world,ofVec3f(i,0,j),0,_tile_width,_elevation,_tile_width);
        _tile_box->setProperties(.25,.75);
        _tile_box->add();
        _tile_boxes.push_back(_tile_box);
         
        if(_type == TEST) {
            shared_ptr <ofxBulletBox> _box(new ofxBulletBox());
            _box->create(world.world,ofVec3f(i,_elevation/2,j),.5,_tile_width,4,_tile_width);
            _box->add();
    
            _boxes.push_back(_box);
        }
}
}

        //_spotlight.setPosition(_tile_boxes[((_total_tiles-_steps)/2)].getX(),_tile_boxes[((_total_tiles-_steps)/2)].getY(),175);
    //} else {
        //plane.setPosition(_map_width/2,_map_width/2,0);
    //}
//_spotlight.lookAt(ofVec3f(ofMap(ofNoise(_spotlight_x),0,1,_x_width-_map_width,_x_width),ofMap(ofNoise(_spotlight_y),0,1,0,_map_width),0));

//_spotlight_x += 0.005;
//_spotlight_y += 0.005;



}
