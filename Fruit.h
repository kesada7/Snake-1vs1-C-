#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED

class Fruit{
private:
    int x;
    int y;
    int points;

public:
    Fruit(int xPos, int yPos, int pointsP);
    ~Fruit(){}

    //setters and getters
    int getX();
    int getY();
    int getPoints();
    void setX(int sX);
    void setY(int sY);


};


#endif // FRUIT_H_INCLUDED
