#pragma once
#include<cmath>
#include "ofMain.h"

class FractalMode{

    public:
    virtual void draw() = 0;
    virtual void setActivate(bool) = 0;
    virtual bool getActivate() = 0;
    virtual void setLevels(int) = 0;
    virtual int getLevels() = 0;
    virtual void setX(int) = 0;
    virtual void setY(int) = 0;
};