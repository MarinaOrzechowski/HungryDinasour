#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
protected:
	Vector2f position;
	Sprite ballSprite;
	Texture ballTexture;
//	RectangleShape ballShape;

	float xVelocity = .2f;
	float yVelocity = .2f;

public:
	Ball(float startX, float startY);
	FloatRect getPosition();
//	RectangleShape getShape();
	Sprite getSprite();
	float getXVelocity();
	void reboundSides();
	void eaten();
	void hitBottom();
	void update();
};
