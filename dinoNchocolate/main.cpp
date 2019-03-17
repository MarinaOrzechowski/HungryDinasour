#include "pch.h"
#include "dino.h"
#include "ball.h"
#include "text_format.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 640;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Hungry Dinosaur");
	
	Sprite BackgroundSprite;
	Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("background.jpg");
	BackgroundSprite.setTexture(BackgroundTexture);

	int score = 0;
	int lives = 3;

	Dino dino(windowWidth / 2, windowHeight*0.55);
	Ball ball(windowWidth / 2, 1);

	Text score_message, header_message1, header_message2, win_message, fail_message;
	Font font;
	font.loadFromFile("dinosaur.ttf");

	header_message1 = textFormat(header_message1, "Hungry Dinosaur", font, windowWidth*0.1, windowHeight*0.05,
		70, Color::Green);
	header_message2 = textFormat(header_message2, "Hungry Dinosaur", font, windowWidth*0.105, windowHeight*0.05,
		70, Color::Black);
	win_message = textFormat(win_message, "'You won!'\n- said happy dinosaur", font, windowWidth*0.05, windowHeight*0.3,
		60, Color::Black);
	fail_message = textFormat(fail_message, "'You lost!'\n- said sad dinosaur", font, windowWidth*0.10, windowHeight*0.3,
		60, Color::Black);
	score_message = textFormat(score_message, "", font, windowWidth*0.10, windowHeight*0.25,
		50, Color::Black);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (lives <= 0) {	
			window.clear();
			window.draw(BackgroundSprite);
			window.draw(fail_message);
			window.display();

		}
		else if (score >= 10) {
			window.clear();
			window.draw(BackgroundSprite);
			window.draw(win_message);
			window.display();		
		}
		else {

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				dino.moveLeft();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				dino.moveRight();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				dino.jump();
			}
			else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			if (ball.getPosition().top > windowHeight)
			{
				ball.hitBottom();
				lives--;
			}

			if (ball.getPosition().intersects(dino.getPosition()))
			{
				ball.eaten();
				score++;
			}

			ball.update();
			dino.update();
			std::stringstream ss;
			ss << "Score:" << score << "    Lives:" << lives;
			score_message.setString(ss.str());
			window.clear();


			window.draw(BackgroundSprite);
			window.draw(header_message1);
			window.draw(header_message2);
			window.draw(dino.getSprite());
			window.draw(ball.getSprite());
			window.draw(score_message);

			window.display();
			window.clear();
		}
	}

	return 0;
}