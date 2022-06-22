#pragma once
#include "FractalMode.h"


class Triangle:public FractalMode{
    private:
    bool activate;
    float xPosition; // x
    float yPosition; // y
    float shapeSize; // size
    int levels; // n

    public:
    Triangle(float, float, float, int);
    void draw();
    void triangleDrawer(float, float, float, int);

    // setter
    void setActivate(bool);
    void setLevels(int);
    void setX(int);
    void setY(int);

    // getters
    bool getActivate();
    int getLevels();
};