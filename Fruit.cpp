#include "Fruit.h"
#include <iostream>


Fruit::Fruit(int xPos, int yPos, int pointsP){
    x = xPos;
    y = yPos;
    points = pointsP;

}

    //setters and getters
    int Fruit::getX(){
        return x;
    }
    int Fruit::getY(){
        return y;
    }
    int Fruit::getPoints(){
        return points;
    }
    void Fruit::setX(int sX){
        x = sX;
    }

    void Fruit::setY(int sY){
        y = sY;
    }
