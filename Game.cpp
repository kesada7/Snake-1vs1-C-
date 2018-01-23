#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
Game::Game()
{

}


void Game::start()
{
/*    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
*/

}

void Game::update()
{

}

void Game::render()
{
    //window.clear();
}

void Game::run()
{
    start();
    while(isPlay)
    {
        update();
        render();
    }
}
