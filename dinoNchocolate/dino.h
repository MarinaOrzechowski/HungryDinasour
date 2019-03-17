#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Dino
{
private:
	Vector2f position;
	Sprite dinoSprite;
	Texture dinoTexture;
	//RectangleShape dinoShape;
	float dinoSpeed = .2f;
	float dinoVelocityX;
	float dinoVelocityY;
	float dinoAccelerationX;
	float dinoAccelerationY;
	float dinoGravity;

public:
	Dino (float startX, float startY);
	FloatRect getPosition();
//	RectangleShape getShape();
	Sprite getSprite();
	void moveLeft();
	void moveRight();
	void jump();
	void update();
};
