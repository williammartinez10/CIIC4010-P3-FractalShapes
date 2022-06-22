#pragma once
#include "FractalMode.h"


class Rectangles:public FractalMode{
    private:
    bool activate;
    int xPosition;
    int yPosition;
    int levels;
    int shapeWidth;
    int shapeHeight;

    public:
    Rectangles(int, int, int, int, int);
    void draw();
    void rectanglesDrawer(int, int, int, int, int);

    //setters
    void setActivate(bool);
    void setLevels(int);
    void setX(int);
    void setY(int);

    //getters
    bool getActivate();
    int getLevels();
    
};