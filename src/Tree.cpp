
#include "Tree.h"

Tree::Tree(int length, int n, int x, int y, int d){
    activate = false;
    this->xPosition = x;
    this->yPosition = y;
    this->treeD = d;
    this->levels = n;
    this->len = length;
}

void Tree::draw(){
    treeDrawer(len, levels, xPosition, yPosition, treeD);
}

void Tree::treeDrawer(int length, int n, int x, int y, int d){
    if(n != 0){

        if(n%2 == 0){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        } else {
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        }

        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*d);
        int leftBranchY = middleY -length*sin(PI/180*d);
        int rightBranchX = x +length*cos(PI/180*d);
        int rightBranchY = middleY -length*sin(PI/180*d);

        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        treeDrawer(length/2, n-1,rightBranchX,rightBranchY, 30+ofRandom(40));
        treeDrawer(length/2,n-1,leftBranchX,leftBranchY, 30+ofRandom(40));
    }
}

void Tree::setActivate(bool command){
    activate = command;
}

bool Tree::getActivate(){
    return activate;
}

void Tree::setLevels(int givenNumber){
    levels = givenNumber;
}

int Tree::getLevels(){
    return levels;
}
void Tree::setX(int givenNumber){
    xPosition = givenNumber;
}
void Tree::setY(int givenNumber){
    yPosition = givenNumber;
}