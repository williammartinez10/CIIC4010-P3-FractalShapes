#pragma once
#include<cmath>

#include "ofMain.h"

#include "Triangle.h"

#include "Tree.h"

#include "Circles.h"

#include "Rectangles.h"

#include "FractalMode.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		FractalMode* rectangles;
		FractalMode* triangle;
		FractalMode* tree;
		FractalMode* circles;
		vector<FractalMode*> modes = {};
		void animation();
		bool toAnimate;
};
