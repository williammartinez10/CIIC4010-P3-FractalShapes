#pragma once
#include "FractalMode.h"


class Tree:public FractalMode{
    private:
    bool activate;
    int xPosition; // x
    int yPosition; // y
    int treeD; // d
    int levels; // n
    int len; // length

    public:
    Tree(int, int, int, int, int);
    void draw();
    void treeDrawer(int, int, int, int, int);

    // setters
    void setActivate(bool);
    void setLevels(int);
    void setX(int);
    void setY(int);

    // getters
    bool getActivate();
    int getLevels();
};