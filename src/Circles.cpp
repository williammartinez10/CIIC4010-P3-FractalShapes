
#include "Circles.h"

Circles::Circles(int x, int y, int n){
    activate = true;
    this->xPosition = x;
    this->yPosition = y;
    this->levels = n;
}

void Circles::draw(){
    circleDrawer(xPosition, yPosition, levels);
}

void Circles::circleDrawer(int x, int y, int n){
    if(n!=0){
        
        if(n%2 == 0){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        } else {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        }

        ofDrawCircle(x, y, 56/2*n);
        circleDrawer(x+66, y, n-1);
        circleDrawer(x-66, y, n-1);
        circleDrawer(x, y+66, n-1);
        circleDrawer(x, y-66, n-1);
    }
}

void Circles::setActivate(bool command){
    activate = command;
}

bool Circles::getActivate(){
    return activate;
}

void Circles::setLevels(int givenNumber){
    levels = givenNumber;
}

int Circles::getLevels(){
    return levels;
}
void Circles::setX(int givenNumber){
    xPosition = givenNumber;
}
void Circles::setY(int givenNumber){
    yPosition = givenNumber;
}