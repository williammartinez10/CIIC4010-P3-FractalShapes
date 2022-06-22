#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(1);
    rectangles = new Rectangles(ofGetWidth()/2, ofGetHeight()/2, 12, 200, 100); // custom fractal/drawMode
    triangle = new Triangle(ofGetWidth() / 3, 10, ofGetHeight() / 2, 10);  // drawMode3
    tree = new Tree(200, 10, ofGetWidth()/2, ofGetHeight()-50, 30); // drawMode2
    circles = new Circles(ofGetWidth()/2, ofGetHeight()/2, 4); // drawMode1
    modes.push_back(circles);
    modes.push_back(tree);
    modes.push_back(triangle);
    modes.push_back(rectangles);
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
    triangle->setX(ofGetWidth() / 3);
    // triangle->setY(ofGetHeight()/3); this puts the triangle on the middle of the screen
    tree->setX(ofGetWidth()/2);
    tree->setY(ofGetHeight()-50);
    circles->setX(ofGetWidth()/2);
    circles->setY(ofGetHeight()/2);
    rectangles->setX(ofGetWidth()/4);
    rectangles->setY(ofGetHeight()/4);
    if(toAnimate){
        animation();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    ofSetColor(255, 255, 255);

    ofDrawBitmapString("Press '1' to draw Circles Fractal", ofGetWidth()-310, 15);
    ofDrawBitmapString("Press '2' to draw Tree Fractal", ofGetWidth()-310, 30);
    ofDrawBitmapString("Press '3' to draw Triangles Fractal", ofGetWidth()-310, 45);
    ofDrawBitmapString("Press '4' to draw Custom/Our Fractal", ofGetWidth()-310, 60);


    ofDrawBitmapString("Press '-' to lower fractal depth", ofGetWidth()-310, 90);
    ofDrawBitmapString("Press '=' to increase fractal depth", ofGetWidth()-310, 105);
    ofDrawBitmapString("Press space bar to activate animation", ofGetWidth()-310, 120);

    if(modes[0]->getActivate()){
        ofDrawBitmapString("Circles Fractal Activated!", 20, 15);
        ofDrawBitmapString("Circle Depth: " + to_string(modes[0]->getLevels()), 20 , ofGetHeight()-10);
        modes[0]->draw();
    }
    if(!modes[0]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Circles Fractal Deactivated", 20, 15);
    }
    if(modes[1]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Tree Fractal Activated!", 20, 30);
        ofDrawBitmapString("Tree Depth: " + to_string(modes[1]->getLevels()), 20 , ofGetHeight()-25);
        modes[1]->draw();
    }
    if(!modes[1]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Tree Fractal Deactivated", 20, 30);
    }
    if(modes[2]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Triangles Fractal Activated!", 20, 45);
        ofDrawBitmapString("Triangle Depth: " + to_string(modes[2]->getLevels()), 20 , ofGetHeight()-40);
        modes[2]->draw();
    }
    if(!modes[2]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Triangles Fractal Deactivated", 20, 45);
    }
    if (modes[3]->getActivate()){ // mode4 is the custom fractal mode (made by us)
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Custom/Our Fractal Activated!", 20, 60);
        ofDrawBitmapString("Rectangle Depth: " + to_string(modes[3]->getLevels()), 20 , ofGetHeight()-55);
        modes[3]->draw();
    }
    if(!modes[3]->getActivate()){
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Custom/Our Fractal Deactivated", 20, 60);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            if(!modes[0]->getActivate()){
                modes[0]->setActivate(true);
            }
            else{
                modes[0]->setActivate(false);
            }
            break;
        case '2':
            if(!modes[1]->getActivate()){
                modes[1]->setActivate(true);
            }
            else{
                modes[1]->setActivate(false);
            }
            break;
        case '3':
            if(!modes[2]->getActivate()){
                modes[2]->setActivate(true);
            }
            else{
                modes[2]->setActivate(false);
            }
            break;
        case '4':
            if(!modes[3]->getActivate()){
                modes[3]->setActivate(true);
            }
            else{
                modes[3]->setActivate(false);
            }
            break;
        case '-':
            if(modes[0]->getLevels() > 0 && modes[0]->getActivate()){
                circles->setLevels(circles->getLevels()-1);
            }
            if(modes[1]->getLevels() > 0 && modes[1]->getActivate()){
                tree->setLevels(tree->getLevels()-1);
            }
            if(modes[2]->getLevels() > 0 && modes[2]->getActivate()){
                triangle->setLevels(triangle->getLevels()-1);
            }
            if(modes[3]->getLevels() > 0 && modes[3]->getActivate()){
                rectangles->setLevels(rectangles->getLevels()-1);
            }
            break;
        case '=':
            if(modes[0]->getLevels() >= 0 && modes[0]->getActivate()){
                circles->setLevels(circles->getLevels()+1);
            }
            if(modes[1]->getLevels() >= 0 && modes[1]->getActivate()){
                tree->setLevels(tree->getLevels()+1);
            }
            if(modes[2]->getLevels() >= 0 && modes[2]->getActivate()){
                triangle->setLevels(triangle->getLevels()+1);
            }
            if(modes[3]->getLevels() >= 0 && modes[3]->getActivate()){
                rectangles->setLevels(rectangles->getLevels()+1);
            }
            break;
        case ' ':
            if (modes[0]->getActivate()){
               modes[0]->setLevels(-1); 
            }
            if (modes[1]->getActivate()){
                modes[1]->setLevels(-1);
            }
            if (modes[2]->getActivate()){
                modes[2]->setLevels(-1);
            }
            if (modes[3]->getActivate()){
                modes[3]->setLevels(-1);
            }
            toAnimate = true;
            
            
           

    }
}

void ofApp::animation(){
    if(modes[0]->getLevels()<4){
        modes[0]->setLevels(modes[0]->getLevels()+1);
    }
    if (modes[1]->getLevels()<10){
        modes[1]->setLevels(modes[1]->getLevels()+1);
    }
    if (modes[2]->getLevels()<10){
        modes[2]->setLevels(modes[2]->getLevels()+1);
    }
    if (modes[3]->getLevels()<15){
        modes[3]->setLevels((modes[3]->getLevels()+1));
    }
    if (modes[0]->getLevels()>=4 && modes[1]->getLevels()>=10 && modes[2]->getLevels()>=10 && modes[3]->getLevels()>=12){
        toAnimate = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}