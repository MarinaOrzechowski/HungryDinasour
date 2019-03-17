#pragma once
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
Text textFormat(Text& target, const String message, const Font& font, float positionX, float positionY,
	unsigned int charSize, const Color& color, float lineSpace = 2)
{
	target.setFont(font);
	target.setString(message);
	target.setPosition(positionX, positionY);
	target.setCharacterSize(charSize);
	target.setLineSpacing(lineSpace);
	target.setFillColor(color);
	return target;
}