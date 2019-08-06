#include "ofApp.h"

void ofApp::setup() {

_w = ofGetWidth();
_h = ofGetHeight();

_draw_sys_info = false;
_draw_sys_count = 0;
font.load("arial.ttf",10);

_elevation = 0;
_elevation_reverse = 0;

_cave_height = 0;

_r = 1000000;   
//_r = ofRandom(0,4000000);   
_r2 = ofRandom(0,_r);

//_scale = ofRandom(100,195);
_scale = 150;
_map_width = 256;
_tile_width = 4;
_steps = _map_width / _tile_width;
_total_tiles = _steps * _steps;

ofBackground(0);

ofSeedRandom();

cam.setPosition(ofVec3f(250,250,250));
cam.lookAt(ofVec3f(0,0,0));

cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_LEFT);
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_TRANSLATE_Z,OF_MOUSE_BUTTON_RIGHT);
cam.addInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_RIGHT);

//shader.load("data/render.vert","data/render.frag");

//lp.loc(128,,_elevation/2,128);
//lp.wh(4,4);
//lp.setup();

map_init();

orb.setup();
ico.setup();
//lp.loc(ofVec3f(128,65,128));
//lp.wh(4,4);
//lp.setup();



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
    
    //_tile_boxes.clear();
    //_tile_box_color.clear();
    //_boxes.clear();
    //_cave_box_color.clear();
    //_cave_boxes.clear();
    }

}

void ofApp::keyReleased(int key) {

    if(key == 'i' && _draw_sys_count > 0) {
    
    //_draw_sys_info = false;
    //_draw_sys_count = 0;
    }

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

void ofApp::mouseMoved(int x,int y) {

//mouse.x = _x;
//mouse.y = _y;

}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST); 
//ofSetSmoothLighting(true);

if(_draw_sys_info == true) {
system_info();
}

cam.begin();

orb.draw();
ico.draw();

//lp.draw();

    for(unsigned int i = 0; i < boxes_layer1.size(); ++i) {
        ofSetColor(box_color[i]);
        boxes_layer1[i].draw();
    }
     
    for(unsigned int i = 0; i < boxes_layer2.size(); ++i) {
        ofSetColor(ofColor(100,100,100));
        boxes_layer2[i].draw();
    }

//shader.begin();
//ofDrawRectangle(0,0,_w/2,_h/2);
//shader.end();   

cam.end();
}

void ofApp::update() {

orb.update();
ico.update();
//lp.update();
}

void ofApp::map_init() {

    for( int i = -(_map_width/2) ; i <= _map_width/2; i+= _tile_width) {
        for( int j = -(_map_width/2) ; j <= _map_width/2; j+= _tile_width) {  
               
        _n =  (  noise.octave(4,(i+_r)*_scale*0.00001,(j+_r)*_scale*0.00001,.5,2) ) ;
        _n2 =  noise2.octave(4,(i+_r2)*(_scale)*0.00001,(j+_r2)*(_scale)*0.00001,.5,2) ;
        _elevation_reverse = _n2*(_scale);
        if(_n < .35) {
        _c.setHsb(105,100,200);
        _elevation = 0;
        } else {
        _c.setHsb(0,0,_n*255);
        _elevation = _n*_scale;
        }
        
        box_color.push_back(_c);
        box1.set(_tile_width,_elevation,_tile_width);
        box2.set(_tile_width,_elevation/2,_tile_width);
        box1.setPosition(i,_elevation/2,j);
        box2.setPosition(i,_elevation/2,j);
        boxes_layer1.push_back(box1);
        boxes_layer2.push_back(box2);
        
    
}
}



}
