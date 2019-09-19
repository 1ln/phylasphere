#include "ofApp.h"

void ofApp::setup() {

w = ofGetWidth();
h = ofGetHeight();
  
shader_test = true;

_draw_sys_info = false;
_draw_sys_count = 0;
keypress_i_ = 0;
n = 0;

noise3d();
system.setup();

ofBackground(0);

ofSeedRandom();

cam.setPosition(ofVec3f(0,0,5));
//cam.setDistance(75); 
cam.lookAt(ofVec3f(0,0,0));

//settings.mouseButtonsReversed(cam);

shader.load("render.vert","render.frag");

//df.shaderSetup();
r1 = ofRandom(0,1);
//shader.setUniform1f("u_random_hash",r1);

//planet.setup();

ofSetGlobalAmbientColor(ofColor(0,0,0));

}

void ofApp::keyPressed(int key) {

    if(key == 'i') {
    _draw_sys_info = true;
    ++_draw_sys_count;
    keypress_i_ = true;
    //shader.setUniform1i("u_keypress_i",1);
    }
    if(_draw_sys_count > 1) {
    _draw_sys_info = false;
    _draw_sys_count = 0;

    }

    if(key == 'r') {
    
    }

}

void ofApp::keyReleased(int key) {
    
    if(key == 'i') {
    keypress_i_ = false;
    //shader.setUniform1i("u_keypress_i",);
    }
} 

void ofApp::mouseMoved(int x,int y) {

mouse.x = x;
mouse.y = y;

}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST);
ofEnableLighting();
ofSetSmoothLighting(true);

if(_draw_sys_info == true) {
//system.display();
}
 
if(shader_test == true) {

shader.begin();

//float n2 = noise3d();

cam.setDistance(5);
//cout << n2 << endl;
shader.setUniform2f("u_resolution",ofGetWidth(),ofGetHeight());
shader.setUniform1f("u_time",ofGetElapsedTimef());
shader.setUniform1f("u_random_hash",r1);
shader.setUniform1f("u_random",ofRandom(0,1));
shader.setUniform3f("u_cam_position",cam.getGlobalPosition());
shader.setUniform2f("u_mouse",mouse.x,mouse.y);
shader.setUniform1f("u_noise",1.0);
shader.setUniform1i("u_keypress_i",keypress_i_);

//noise3d();
//shader.setUniform1fv("u_test",&test[0],test.size());
shader.setUniform1fv("u_test",&test[0],100);
ofDrawRectangle(0,0,w,h);

//cam.begin();
//cout << df.sphere(glm::vec3(0,0,0),glm::vec3(0,0,0),2.0) << endl;


//cam.end();

shader.end();
//df.updateUniforms();
//df.shaderDraw();

cam.begin();
cam.end();

} else { 

cam.begin();
//planet.draw();
cam.end();

}
}

void ofApp::update() {

w_mouse = cam.screenToWorld(ofVec3f(mouse.x,mouse.y,0.0f));
w_mouse_end = cam.screenToWorld(ofVec3f(mouse.x,mouse.y,1.0f)); 

mouse_transmission = w_mouse_end - w_mouse;
mouse_ray.s = w_mouse;
mouse_ray.t = mouse_transmission;
//cout << (mouse_ray.distanceTo(ofVec3f(0,0,0))-250) << endl;
//cout <<  df.sphere( mouse_transmission ,glm::vec3(0,0,0),2.0 )  << endl;
//float n2 = noise3d();
//cout << n2 << endl;
}


void ofApp::noise3d() {
float n1;
for(int i = 0; i < 100; ++i) {
    //for(float j = 0; j < 10; ++j) {
        //for(float k = 0; k < 10; ++k) {
        
        //n1 = noise.fb3(ofVec3f(ofGetElapsedTimeMillis()%100,ofGetElapsedTime()%50 ,ofGetElapsedTimeMillis()%25));
        //n1 = ofRandom(0,1);
        n1 = noise.fb3(ofVec3f( i+2,i+3,i+4));
        //n1 = noise.fb3(ofVec3f(i,j,k));
        test[i] = n1;
        //test.push_back(n1);
        //cout << n1 << endl;
//}}}
} 

//return n1;
}



//star.update();
//moon.update();
//planet.update();
//}
