
#include "Triangle.h"

Triangle::Triangle(float x, float y, float size, int n){
    activate = false;
    this->xPosition = x;
    this->yPosition = y;
    this->shapeSize = size;
    this->levels = n;
}

void Triangle::draw(){
    triangleDrawer(xPosition, yPosition, shapeSize, levels);
}

void Triangle::triangleDrawer(float x, float y, float size, int n){
    if(n == 0) {
        return;
    }

    if(n%2 == 0){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    } else {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    Triangle::triangleDrawer(x, y, size / 2, n - 1);
    Triangle::triangleDrawer((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    Triangle::triangleDrawer((a.x+c.x)/2, (a.y+c.y)/2, size/2, n-1);
}

void Triangle::setActivate(bool command){
    activate = command;
}

bool Triangle::getActivate(){
    return activate;
}

void Triangle::setLevels(int givenNumber){
    levels = givenNumber;
}

int Triangle::getLevels(){
    return levels;
}
void Triangle::setX(int givenNumber){
    xPosition = givenNumber;
}
void Triangle::setY(int givenNumber){
    yPosition = givenNumber;
}