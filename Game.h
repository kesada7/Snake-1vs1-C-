#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>

class Game{

    protected:

    //map size (not in pixel is in "size" square)
    int N=35,M=30;
    // size of the square
    int size=16;
    //map size
    int w = size*N;
    int h = size*M;



    bool isPlay{true};

/*    sf::RenderWindow window;

    sf::Event event;


*/
private:
    void start();
    void update();
    void render();


public:
    Game();
    ~Game(){}

    //Getters and setters
    int getN()
    {
        return N;
    }
    int getM()
    {
        return M;
    }
    int getSize()
    {
        return size;
    }
    //draw map
//    void drawMap(Sprite sprite1);

    void run();


};

#endif // GAME_H_INCLUDED
