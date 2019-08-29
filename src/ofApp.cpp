#include "ofApp.h"

void ofApp::setup() {

w = ofGetWidth();
h = ofGetHeight();
  
shader_test = true;

_draw_sys_info = false;
_draw_sys_count = 0;
font.load("arial.ttf",10);

ofBackground(0);

ofSeedRandom();

cam.setPosition(ofVec3f(0,0,75));
cam.lookAt(ofVec3f(0,0,0));

mouse_reverse = false;
if(mouse_reverse == true) {
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_LEFT);
cam.removeInteraction(ofEasyCam::TransformType::TRANSFORM_TRANSLATE_Z,OF_MOUSE_BUTTON_RIGHT);
cam.addInteraction(ofEasyCam::TransformType::TRANSFORM_ROTATE,OF_MOUSE_BUTTON_RIGHT);
}

shader.load("render.vert","render.frag");


r1 = ofRandom(0,1);
//shader.setUniform1f("u_random",r1);

star.setup();
//moon.setOrbiting(true);
//moon.orb.orbitalSpeed(0.1);
//moon.orb.rotationalSpeed(0.1);
//moon.setRotationalSpeed(0.01);
//moon.setOrbitalSpeed(0.01);
//planet.setRotatingOnAxis(true);
planet.setHeight(25);
//moon.setRadius(50);
//moon.setDistanceFromCenter(350);
//moon.setPosition(ofVec3f(350,0,0));
//moon.setup();
planet.setup();

ofSetGlobalAmbientColor(ofColor(0,0,0));

}

void ofApp::system_info() {

string fps = "FPS: " + ofToString(ofGetFrameRate(),2);
font.drawString(fps,15,15);

string millis = "Millis since start: " + ofToString(ofGetElapsedTimeMillis(),2);
font.drawString(millis,15,30);

string version = "Openframeworks version: " + ofToString(ofGetVersionInfo(),2);
font.drawString(version,15,45);

string cam_position = "Camera Position: " + ofToString(cam.getPosition(),2);
font.drawString(cam_position,15,60);

string cam_lookat = "Camera Look At: " + ofToString(cam.getLookAtDir(),2);
font.drawString(cam_lookat,15,75);

string cam_fov = "Camera FOV: " + ofToString(cam.getFov(),2);
font.drawString(cam_fov,15,90);



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

void ofApp::mouseMoved(int x,int y) {

mouse.x = x;
mouse.y = y;

}

void ofApp::draw() {

glEnable(GL_DEPTH_TEST);
ofEnableLighting();
ofSetSmoothLighting(true);
if(_draw_sys_info == true) {
system_info();
}
 
//ofTranslate(planet.g_Position());
//cam.setParent(planet.ico);
//cam.setPosition(planet.g_Position());
//cam.setTarget(planet.g_Position());
//cam.lookAt(planet.g_Position());
//cam.begin();
 
if(shader_test == true) {
shader.begin();
cam.begin();
shader.setUniform2f("u_resolution",w,h);
shader.setUniform1f("u_time",ofGetElapsedTimef());
shader.setUniform1f("u_random",r1); 

shader.setUniform3f("u_cam_position",cam.getGlobalPosition());

//cam.begin();
//ofTranslate(0,0);
ofDrawRectangle(0,0,w,h);
//star.draw();
//planet.draw();

cam.end();
shader.end();
} else { 

cam.begin();
star.draw();
//moon.draw();
planet.draw();
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
//cout << (mouse_ray.distanceTo(ofVec3f(2000,0,0))-100) << endl;

star.update();
//moon.update();
planet.update();
}
