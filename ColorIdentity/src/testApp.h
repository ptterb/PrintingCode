#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    void generateColors();
    
    vector<ofPoint> points;
    
    vector<ofColor> colors;
    vector<ofVec3f> triangles;
    
    int numColors = 5;
    
    int currentPoint;
    float myHue;
    
    bool debug = false;
    bool saveScreen = false;
		
};
