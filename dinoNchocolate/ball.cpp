#include "pch.h"
#include "Ball.h"
#include <ctime>
#include <cstdlib>

// This the constructor and it is called when we create an object
Ball::Ball(float startX, float startY)
{
	ballTexture.loadFromFile("chocolate.png");
	ballSprite.setTexture(ballTexture);
	position.x = startX;
	position.y = startY;
	ballSprite.setPosition(position);
}
FloatRect Ball::getPosition()
{
	return ballSprite.getGlobalBounds();
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::eaten()
{
	position.y = 1;
	position.x = rand() % 1023 + 1;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = rand() % 1023 + 1;
}

void Ball::update()
{
	position.y += yVelocity;

	ballSprite.setPosition(position);
}

Sprite Ball::getSprite()
{
	return ballSprite;
}