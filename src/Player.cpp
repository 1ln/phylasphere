#include "Player.h"

Player::Player() {
_x = 0;
_y = 0;
_radius = 0;
_speed = 0;
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
player.set(4,4,4);
player.setPosition(_x,_y,125);
} 
 
void Player::drawPlayer() {

    //player.draw(); 
}

void Player::draw() {
player.draw();
}

void Player::update() {

}

void Player::forward() {
_speed += 4;
//player.move(player.getYAxis()*_speed);
}

void Player::back() { 
_speed -= 4 ;
//cout << _speed << endl;
//player.move(player.getYAxis()*(-_speed));
}

void Player::left() {
_speed += 4;
//player.move(player.getXAxis()*_speed);
}

void Player::right() {
_speed -= 4;
//player.move(player.getXAxis()*(-_speed));
}

float Player::getSpeed() {
return _speed;
}
