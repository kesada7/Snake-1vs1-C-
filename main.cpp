/*
  Snake ICA start project using SFML
    SFML documentation: http://www.sfml-dev.org/documentation/2.4.2/classes.php
  Windows build
    To build on Windows you need to have the correct version of CodeBlocks
      Download from here: http://www.codeblocks.org/downloads/26
      Must be the download titled "codeblocks-16.01mingw-setup.exe"
*/

#include <iostream>
#include <string>
#include <sstream>
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"


#include <time.h>

std::string NumberToString ( int Number );
using namespace sf;


int main()
{

// Declare and load a font
sf::Font font;
font.loadFromFile("fonts/ARCADECLASSIC.TTF");
// //////Create info text////////////
////////////////////////////////
sf::Text welcome("welcome   to   the   snake   game", font);
welcome.setCharacterSize(30);
welcome.setStyle(sf::Text::Bold);
welcome.setColor(sf::Color::Blue);
welcome.setPosition(600,30);

sf::Text player1("Player 1 use Arrow keys for control", font);
sf::Text player2("Player 2 use AWSD keys for control", font);
player1.setCharacterSize(20);
player1.setStyle(sf::Text::Bold);
player1.setColor(sf::Color::Green);
player1.setPosition(630,100);
player2.setCharacterSize(20);
player2.setStyle(sf::Text::Bold);
player2.setColor(sf::Color::Red);
player2.setPosition(630,160);

sf::Text fruit1Info("x 1", font);
sf::Text fruit2Info("x 2", font);
sf::Text fruit3Info("x 3", font);
fruit1Info.setCharacterSize(20);
fruit1Info.setStyle(sf::Text::Bold);
fruit1Info.setColor(sf::Color::White);
fruit1Info.setPosition(830,300);
fruit2Info.setCharacterSize(20);
fruit2Info.setStyle(sf::Text::Bold);
fruit2Info.setColor(sf::Color::White);
fruit2Info.setPosition(830,340);
fruit3Info.setCharacterSize(20);
fruit3Info.setStyle(sf::Text::Bold);
fruit3Info.setColor(sf::Color::White);
fruit3Info.setPosition(830,380);

Game game;

Snake snake1(4,4);
Snake snake2(4,20);

Fruit fruit1(6,6, 1);
Fruit fruit2(20, 20, 2);
Fruit fruit3(30, 10, 3);

bool gameOver = false, snake1Crash = false, snake2Crash = false;



	//

    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    RenderWindow window(VideoMode(1100, 700), "C++ Snake ICA : s6213249");
    window.setFramerateLimit(60); //limited frames
    window.setKeyRepeatEnabled(false); //with this we key don't repeat if we let the key pressed


	//Sprites we are going to use for the snake and fruits
	Texture t1,t2, t3, t4, t5, t6;
	t1.loadFromFile("images/map.png");
	t2.loadFromFile("images/fruit1.png");
	t3.loadFromFile("images/body.png");
	t4.loadFromFile("images/body2.png");
    t5.loadFromFile("images/fruit2.png");
    t6.loadFromFile("images/fruit3.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
    Sprite sprite3(t3);
    Sprite sprite4(t4);
    Sprite sprite5(t5);
    Sprite sprite6(t6);


	//We use clock to set a delay  to control game speed and ensure the game run in all devices with same delay
	//So we can used this to fix the snake speed and simulated "level" or "difficulty"
	Clock clock;
    float timer=0, delay=0.1, timerGame = 0;


    // Main loop that continues until we call Close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.

		float time = clock.getElapsedTime().asSeconds();
		float timeGame = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;
        timerGame+=timeGame;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
		}


        //Snake 1 control
		if (Keyboard::isKeyPressed(Keyboard::Left)&&(snake1.direction!=snake1.EDirection::eRight)) snake1.direction = snake1.EDirection::eLeft;
	    if (Keyboard::isKeyPressed(Keyboard::Right)&&(snake1.direction!=snake1.EDirection::eLeft))  snake1.direction=snake1.EDirection::eRight;
	    if (Keyboard::isKeyPressed(Keyboard::Up)&&(snake1.direction!=snake1.EDirection::eDown)) snake1.direction=snake1.EDirection::eUp;
		if (Keyboard::isKeyPressed(Keyboard::Down)&&(snake1.direction!=snake1.EDirection::eUp)) snake1.direction=snake1.EDirection::eDown;

		//Snake2 control
		if (Keyboard::isKeyPressed(Keyboard::A)&&(snake2.direction!=snake2.EDirection::eRight)) snake2.direction = snake2.EDirection::eLeft;
	    if (Keyboard::isKeyPressed(Keyboard::D)&&(snake2.direction!=snake2.EDirection::eLeft))  snake2.direction=snake2.EDirection::eRight;
	    if (Keyboard::isKeyPressed(Keyboard::W)&&(snake2.direction!=snake2.EDirection::eDown)) snake2.direction=snake2.EDirection::eUp;
		if (Keyboard::isKeyPressed(Keyboard::S)&&(snake2.direction!=snake2.EDirection::eUp)) snake2.direction=snake2.EDirection::eDown;


		//Delay to move the snake

		if (timer>delay && gameOver==false) {
                timer=0;
                snake1.moveSnake();
                snake2.moveSnake();

                //Check snake collision between each other
                //TODO fix bug that sometimes call game over even is not
                // for (int i=0;i<snake2.getSize();i++)
                //   if (snake1.s[0].x==snake2.s[i].x && snake1.s[0].y==snake2.s[i].y) gameOver = true; snake1Crash = true;
                //for (int i=0;i<snake1.getSize();i++)
                //  if (snake2.s[0].x==snake1.s[i].x && snake2.s[0].y==snake1.s[i].y) gameOver = true; snake1Crash = true;
        }
        if(timerGame >= 60.0){

            gameOver = true;

        }
        //Manage the time left text
        sf::Text timeLeft("Time left 0", font);
        timeLeft.setCharacterSize(20);
        timeLeft.setStyle(sf::Text::Bold);
        timeLeft.setColor(sf::Color::Yellow);
        timeLeft.setPosition(630,320);

        sf::Text playerWon("", font);
        playerWon.setCharacterSize(70);
        playerWon.setStyle(sf::Text::Bold);
        playerWon.setColor(sf::Color::Cyan);
        playerWon.setPosition(610,420);
        if(gameOver == false){
            timeLeft.setString("Time left "+NumberToString(61-timerGame));

        }else{
            if(snake1.getScore()>snake2.getScore()) {playerWon.setString("Player 1 Wins");}
            else if(snake1.getScore()<snake2.getScore()) playerWon.setString("Player 2 Wins");
                  else playerWon.setString("game ended in a tie");
            //if(snake1Crash == true) playerWon.setString("Player 2 Wins");
            //if(snake2Crash == true) playerWon.setString("Player 1 Wins");




        }




    //when snake1 pick fruit
	if ((snake1.s[0].x==fruit1.getX()) && (snake1.s[0].y==fruit1.getY()))
    {
        snake1.growSnake(fruit1.getPoints());
    	fruit1.setX(rand() % game.getN());
        fruit1.setY(rand() % game.getM());

    }
    if ((snake1.s[0].x==fruit2.getX()) && (snake1.s[0].y==fruit2.getY()))
    {
        snake1.growSnake(fruit2.getPoints());
    	fruit2.setX(rand() % game.getN());
        fruit2.setY(rand() % game.getM());

    }
	if ((snake1.s[0].x==fruit3.getX()) && (snake1.s[0].y==fruit3.getY()))
    {
        snake1.growSnake(fruit3.getPoints());
    	fruit3.setX(rand() % game.getN());
        fruit3.setY(rand() % game.getM());

    }


    //when snake2 pick fruit
	if ((snake2.s[0].x==fruit1.getX()) && (snake2.s[0].y==fruit1.getY()))
    {
        snake2.growSnake(fruit1.getPoints());
    	fruit1.setX(rand() % game.getN());
        fruit1.setY(rand() % game.getM());
    }
    if ((snake2.s[0].x==fruit2.getX()) && (snake2.s[0].y==fruit2.getY()))
    {
        snake2.growSnake(fruit2.getPoints());
    	fruit2.setX(rand() % game.getN());
        fruit2.setY(rand() % game.getM());

    }
	if ((snake2.s[0].x==fruit3.getX()) && (snake2.s[0].y==fruit3.getY()))
    {
        snake2.growSnake(fruit3.getPoints());
    	fruit3.setX(rand() % game.getN());
        fruit3.setY(rand() % game.getM());

    }




    sf::Text player1Score("Player 1 score  "+NumberToString(snake1.getScore()-2), font);
    sf::Text player2Score("Player 2 score  "+NumberToString(snake2.getScore()-2), font);
    player1Score.setCharacterSize(20);
    player1Score.setStyle(sf::Text::Bold);
    player1Score.setColor(sf::Color::Green);
    player1Score.setPosition(630,220);
    player2Score.setCharacterSize(20);
    player2Score.setStyle(sf::Text::Bold);
    player2Score.setColor(sf::Color::Red);
    player2Score.setPosition(830,220);



    // We must clear the window each time round the loop
    window.clear();
    // draw our sprites to the window



    //draw map

    for (int i=0; i<game.getN(); i++)
	  for (int j=0; j<game.getM(); j++)
		{
            sprite1.setPosition(i*game.getSize(),j*game.getSize());
            window.draw(sprite1);
        }


    //draw snake1
	for (int i=0;i<snake1.getScore();i++)
	    {
            sprite3.setPosition(snake1.s[i].x*game.getSize(), snake1.s[i].y*game.getSize());
            window.draw(sprite3);
        }
    //draw snake2
	for (int i=0;i<snake2.getScore();i++)
	    {
            sprite4.setPosition(snake2.s[i].x*game.getSize(), snake2.s[i].y*game.getSize());
            window.draw(sprite4);
        }

	//draw fruits
	sprite2.setPosition(fruit1.getX()*game.getSize(),  fruit1.getY()*game.getSize());  window.draw(sprite2);
    sprite5.setPosition(fruit2.getX()*game.getSize(),  fruit2.getY()*game.getSize());  window.draw(sprite5);
    sprite6.setPosition(fruit3.getX()*game.getSize(),  fruit3.getY()*game.getSize());  window.draw(sprite6);


    //draw info fruits
    sprite2.setPosition(805,305);  window.draw(sprite2);
    sprite5.setPosition(805,345);  window.draw(sprite5);
    sprite6.setPosition(805,385);  window.draw(sprite6);

	// Draw text
    window.draw(welcome);
    window.draw(player1);
    window.draw(player2);
    window.draw(player1Score);
    window.draw(player2Score);
    window.draw(timeLeft);
    window.draw(fruit1Info);
    window.draw(fruit2Info);
    window.draw(fruit3Info);
    window.draw(playerWon);


    // Get the window to display its contents
	window.display();
	}

    return 0;
}

//Function to convert int to string
std::string NumberToString ( int Number )
{
	std::stringstream ss;
	ss << Number;
	return ss.str();
}
