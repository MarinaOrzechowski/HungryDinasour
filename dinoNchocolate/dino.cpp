#include "pch.h"
#include "dino.h"

// This the constructor and it is called when we create an object
Dino::Dino(float startX, float startY)
{
	dinoTexture.loadFromFile("dino.png");
	dinoSprite.setTexture(dinoTexture);
	position.x = startX;
	position.y = startY;
	dinoSprite.setPosition(position);

	dinoVelocityX = 0;
	dinoVelocityY = 0;
	dinoAccelerationX = 0;
	dinoAccelerationY = 0;
	dinoGravity = 5;
}
FloatRect Dino::getPosition()
{
	return dinoSprite.getGlobalBounds();
}

//RectangleShape Dino::getShape()
//{
//	return dinoShape;
//}

void Dino::moveLeft()
{
	dinoVelocityX = -dinoSpeed;
}

void Dino::moveRight()
{
	dinoVelocityX = dinoSpeed;
}

void Dino::jump()
{
	dinoVelocityY = -2;

}


void Dino::update()
{



	position.x += dinoVelocityX;
	position.y += dinoVelocityY;

	dinoSprite.setPosition(position);
	if (position.y < 300)
		dinoVelocityY += dinoGravity;
	else if (position.y > 300)
		position.y = 300;
}

Sprite Dino::getSprite()
{
	return dinoSprite;
}
