#include "Player.h"

Player::Player() {
_x = 0;
_y = 0;
_radius = 0;
} 

void Player::setPosition(float x,float y) {
_x = x;
_y = y;
}

void Player::setRadius(float radius) { 
_radius = radius;
}

void Player::setup() {
//ico.setRadius(_radius);
//ico.setResolution(5);
ico.set(5,5,5);
ico.setPosition(_x,_y,0);
} 
 
void Player::drawPlayer() {

    ico.draw(); 
}

void Player::draw() { 
drawPlayer();
//ofNoFill();
ofSetColor(0,255,0,255);
}

void Player::update() {

}

void Player::forward() {
_y++;
ico.setPosition(_x,_y,0);
}

void Player::back() {
_y--;
ico.setPosition(_x,_y,0);
}

void Player::rotateLeft() {
ico.rotateDeg(-1,0,1,0);
}

void Player::rotateRight() {
ico.rotateDeg(1,0,1,0);
}


