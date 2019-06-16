#include "Player.h"

Player::Player() {
_x = 0;
_y = 0;
_radius = 0;
_speed = 10;
} 

void Player::setPosition(float x,float y) {
_x = x;
_y = y;
}

ofVec3f Player::getPosition() {
return player.getPosition();
}

float Player::getX() {
return player.getX();
}

float Player::getY() {
return player.getY();
}

void Player::setRadius(float radius) { 
_radius = radius;
}

void Player::setup() {
//player.setRadius(_radius);
//player.setResolution(5);
player.set(5,5,5);
player.setPosition(_x,_y,0);
} 
 
void Player::drawPlayer() {

    player.draw(); 
}

void Player::draw() { 
drawPlayer();
//ofNoFill();
//ofSetColor(0,255,0,255);
}

void Player::update() {

}

void Player::forward() {
player.move(player.getYAxis()*_speed);
}

void Player::back() {
//_y--;
}

void Player::rotateLeft() {
player.rotateDeg(-10,0,0,1);
}

void Player::rotateRight() {
player.rotateDeg(10,0,0,1);
}


