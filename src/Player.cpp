#include "Player.h"

Player::Player() {
_x = 0;
_y = 0;
_r = 0;
_speed = 0;
_speedX = 0;
_speedY = 0;
} 

void Player::position(float x,float y) {
_x = x;
_y = y;
}

float Player::x() {
return _x;
}

float Player::y() {
return _y;
}

void Player::radius(float r) { 
_r = r;
}

void Player::setup() {
box.set(16,16,16);
box.setPosition(_x,_y,125);
speed(24);
}

void Player::draw() {
box.draw();
}

void Player::update() {
}

void Player::forward() {
_speedX += _speed;
//box.move(player.getYAxis()*_speed);
}

void Player::back() { 
_speedX -= _speed;
//box.move(player.getYAxis()*(-_speed));
}

void Player::left() {
_speedY += _speed;
//box.move(box.getXAxis()*_speedX);
}

void Player::right() {
_speedY -= _speed;
//box.move(box.getXAxis()*(-_speedX));
}

void Player::mouseFromWorld(ofVec3f v) {
_mouse = v;
//cout << _mouse << endl;
}

void Player::rotate(float x,float y) {
_v.set(x,y,0);
float angle = atan2(x,y);
//cout << angle << endl;
box.rotateRad(angle,1,0,0);
//box.lookAt(_v);
}

float Player::speedX() {
return _speedX;
}

float Player::speedY() { 
return _speedY;
}

void Player::speed(float s) {
_speed = s;
}
