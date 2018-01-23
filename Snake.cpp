#include "Snake.h"
#include "Fruit.h"
#include <iostream>

Snake::Snake(int xPos, int yPos){
    s[0].x = xPos;
    s[0].y = yPos;

}


void Snake::moveSnake(){

    //move x and y position following the "head" position
    for (int i=score;i>0;--i)
	 {
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
	 }


    if (direction==EDirection::eDown) s[0].y+=1;
    if (direction==EDirection::eLeft) s[0].x-=1;
    if (direction==EDirection::eRight) s[0].x+=1;
    if (direction==EDirection::eUp) s[0].y-=1;



    //when snake go out map (wall collision) he transport it to the opposite wall " additional features"
    if (s[0].x>N-1) s[0].x=0;
    if (s[0].x<0) s[0].x=N-1;
    if (s[0].y>M-1) s[0].y=0;
    if (s[0].y<0) s[0].y=M-1;


    //when snake collide with himself we broke his tail instead make a "game over" " additional features"
    for (int i=1;i<score;i++)
     if (s[0].x==s[i].x && s[0].y==s[i].y)  score=i;
}

void Snake::growSnake(int fruitPoints){
    score += fruitPoints;
}
int Snake::getScore(){
    return score;
}
