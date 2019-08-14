#include "ofApp.h"

void ofApp::setup() {

//_w = ofGetWidth();
//_h = ofGetHeight();

_draw_sys_info = false;
_draw_sys_count = 0;
font.load("arial.ttf",10);

//_elevation_l0 = 0;
//_elevation_l1 = 0;

//_r = 1000000;   
//_r = ofRandom(0,4000000);   
//_r2 = ofRandom(0,_r);

//_scale = ofRandom(100,195);
//_scale = 150;
//_map_width = 256;
//_tile_width = 4;
//_steps = _map_width / _tile_width;
//_total_tiles = _steps * _steps;

ofBackground(0);

ofSeedRandom();

cam.setPosition(ofVec3f(250,250,250));
cam.lookAt(ofVec3f(0,0,0));

cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_LEFT);
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_TRANSLATE_Z,OF_MOUSE_BUTTON_RIGHT);
cam.addInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_RIGHT);

//lp.wh(4,4);

//map_init();

//for(unsigned int i = 0; i < 3; ++i) {
//orb.radius(ofRandom(200,250));
//orb.speed(ofRandom(0.001,0.005));
//orbs.push_back(orb);


//} 
star.setup();

//mat.setShininess(100);
//mat.setSpecularColor(ofColor(255,255,255,255));
//mat.setEmissiveColor(ofColor(255,0,0));

//ofSetGlobalAmbientColor(ofColor(0,0,0));

}

void ofApp::system_info() {

string fps = "FPS: " + ofToString(ofGetFrameRate(),2);
font.drawString(fps,15,15);

} 

void ofApp::keyPressed(int key) {

    if(key == 'i') {
    _draw_sys_info = true;
    ++_draw_sys_count;
    }
    if(_draw_sys_count > 1) {
    _draw_sys_info = false;
    _draw_sys_count = 0;
    }

    if(key == 'r') {
    
    }

}

void ofApp::keyReleased(int key) {

    if(key == 'i' && _draw_sys_count > 0) {
    
    //_draw_sys_info = false;
    //_draw_sys_count = 0;
    }

    if(key == 'r') {
         //_r = ofRandom(4000000);
         //ofSeedRandom();
         //map_init();
    }
} 

void ofApp::mouseMoved(int x,int y) {

//mouse.x = _x;
//mouse.y = _y;

}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST);
ofEnableLighting();
ofSetSmoothLighting(true);

if(_draw_sys_info == true) {
system_info();
}

cam.begin();

star.draw();
//mat.begin();
    
    
    //for(unsigned int i = 0; i < orbs.size(); ++i) {
        //orbs[i].draw();
    //}

    //for(unsigned int i = 0; i < boxes_layer0.size(); ++i) {
        //ofSetColor(box_color[i]);
        //boxes_layer0[i].draw();
    //}
     
    //for(unsigned int i = 0; i < boxes_layer1.size(); ++i) {
        //ofSetColor(box_color[i]);
        //boxes_layer1[i].draw();
    //}

//mat.end();
cam.end();

//ofDisableLighting();
}

void ofApp::update() {

//for(unsigned int i = 0; i < orbs.size(); ++i) {
//orbs[i].update();
//}
star.update();
}
/*
void ofApp::map_init() {

    for( int i = -(_map_width/2) ; i <= _map_width/2; i+= _tile_width) {
        for( int j = -(_map_width/2) ; j <= _map_width/2; j+= _tile_width) {  
               
        _n0 =  noise0.octave(4,(i+_r)*_scale*0.00001,(j+_r)*_scale*0.00001,.5,2);
        _n1 =  noise1.octave(4,(i+_r2)*(_scale)*0.00001,(j+_r2)*(_scale)*0.00001,.5,2);
        
        _elevation_l0 = _n0*(_scale);
        _elevation_l1 = _n1*(_scale);
        _c.setHsb(0,128,128,.5);
        
        box_color.push_back(_c);
        box0.set(_tile_width,_elevation_l0,_tile_width);
        box1.set(_tile_width,-_elevation_l1,_tile_width);
        box0.setPosition(i,_elevation_l0/2,j);
        box1.setPosition(i,-_elevation_l1/2,j);
        boxes_layer0.push_back(box0);
        boxes_layer1.push_back(box1);
        
    
}
}
*/
//}
