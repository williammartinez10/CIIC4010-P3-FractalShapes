#pragma once
#include "FractalMode.h"


class Circles:public FractalMode{
    private:
    bool activate;
    float xPosition;  // x
    float yPosition; // y
    int levels; // n

    public:
    Circles(int, int, int);
    void draw();
    void circleDrawer(int, int, int);

    //setters
    void setActivate(bool);
    void setLevels(int);
    void setX(int);
    void setY(int);

    //getters
    bool getActivate();
    int getLevels();
};