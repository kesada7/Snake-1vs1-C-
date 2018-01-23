#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "Game.h"

class Snake : public Game
{

private:
    int score = 2;

public:
    struct SnakeBody
    {
        int x =4,
            y=4;
    }s[100];

    enum class EDirection
    {
        eUp,
        eRight,
        eDown,
        eLeft
    };
    EDirection direction = EDirection::eRight;

    //constructor
public:
    Snake(int xPos, int yPos);
    ~Snake(){}
    int getX();
    int getY();
    void setY(int yPos);

public:
    void moveSnake();
    void growSnake(int fruitPoints);
    int getScore();

};


#endif // SNAKE_H_INCLUDED
