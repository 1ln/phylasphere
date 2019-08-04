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

//orb.setup();

//lp.loc(128,,_elevation/2,128);
//lp.wh(4,4);
//lp.setup();

//world.setup();
//world.setGravity(ofVec3f(0,-.9,0));
//world.enableGrabbing();
//world.setCamera(&cam);

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
ofSetSmoothLighting(true);

if(_draw_sys_info == true) {
system_info();
}

cam.begin();

orb.draw();
ico.draw();

//lp.draw();

    //for(unsigned int i = 0; i < _tile_boxes.size(); ++i) {
        //ofSetColor(_tile_box_color[i]);
        //_tile_boxes[i]->draw();
        //_tile_boxes_mesh[i]->getMesh();
    //}

    //for(unsigned int i = 0; i < _cave_boxes.size(); ++i) {
        //ofSetColor(_cave_box_color[i]);
        //ofSetColor(ofColor(100,100,100));
        //_cave_boxes[i]->draw();
    //} 
cout << boxes_mesh.size() << endl;
    for(unsigned int i = 0; i < boxes_mesh.size(); ++i) {
        ofSetColor(ofColor(100,100,100));
        boxes_mesh[i].draw();
    }
    

cam.end();
}

void ofApp::update() {
//world.update();
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
        
        box.set(_tile_width,_elevation,_tile_width);
        box.setPosition(i,_elevation/2,j);
        //box_mesh = box.getMesh();
        //vector<ofMesh> box_mesh = box.getMesh();
        boxes_mesh.push_back(box.getMesh());
        boxes.push_back(box);
        
        //_cave_height = 1;      

        //_tile_box_color.push_back(_c);
    
        //shared_ptr <ofxBulletBox> _tile_box(new ofxBulletBox());
        //_tile_box->create(world.world,ofVec3f(i,_elevation/2,j),0,_tile_width,_elevation,_tile_width);

        //_tile_box->setProperties(.25,.75);
        //_tile_box->add();
        //_tile_boxes.push_back(_tile_box);
        
        //_cave_box_color.push_back(_c);
        //shared_ptr <ofxBulletBox> _cave_box(new ofxBulletBox());
        //_cave_box->setProperties(.25,.75);
        //_cave_box->create(world.world,ofVec3f(i,(-_elevation_reverse/2),j),0,_tile_width,_elevation_reverse+_cave_height,_tile_width);       
        //_cave_box->add();
        //_cave_boxes.push_back(_cave_box);
        

        //if(_type == TEST) {
            //_elevation_dist = ofDist(i,-_scale+(_elevation/2),j,i,(_elevation_reverse),j);
            //cout << "i: " << i << endl;
            //cout << "j: " << j << endl;
            //cout << "elevation - :" << _elevation_reverse/2 << endl;
            //cout << "elevation + :" << _elevation/2 << endl;
            //cout <<  (_elevation_dist) << endl;
            //shared_ptr <ofxBulletBox> _box(new ofxBulletBox());
            //_box->create(world.world,ofVec3f(i,0,j),0,_tile_width,_cave_height,_tile_width);
            //_box->add();
    
            //_boxes.push_back(_box);
         //}
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
