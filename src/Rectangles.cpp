
#include "Rectangles.h"


Rectangles::Rectangles(int x, int y, int n, int w, int h){
    activate = false;
    this->xPosition = x;
    this->yPosition = y;
    this->levels = n;
    this->shapeWidth = w;
    this->shapeHeight = h;
}

void Rectangles::draw(){
    rectanglesDrawer(xPosition, yPosition, levels, shapeWidth, shapeHeight);
}

void Rectangles::rectanglesDrawer(int x, int y, int n, int w, int h){
    if(n != 0){

        if(n%2 == 0){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        } else {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        }

        ofDrawRectangle(x, y, n, w*3, h*4);
        rectanglesDrawer(x+(w/4), y, n-1, w/1.2, h/1.2);
    }
}

void Rectangles::setActivate(bool command){
    activate = command;
}

bool Rectangles::getActivate(){
    return activate;
}

void Rectangles::setLevels(int givenNumber){
    levels = givenNumber;
}

int Rectangles::getLevels(){
    return levels;
}
void Rectangles::setX(int givenNumber){
    xPosition = givenNumber;
}
void Rectangles::setY(int givenNumber){
    yPosition = givenNumber;
}