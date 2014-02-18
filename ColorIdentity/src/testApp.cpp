#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    
    myHue = 136.70;
    
    // Debug mode was used to draw out my points.
    // I played around with the points and the triangles for a while
    // just trying to find what shape I liked.
    // The shape I came up with was inspired by, but didn't use
    // Delaunay triangulation
    if (debug){
        for (int i = 0; i < 10; i++){
            points.push_back(ofPoint(0,0));
        }
        currentPoint = 0;
    } else {
        points.push_back(ofPoint(235, 149));
        points.push_back(ofPoint(366, 93));
        points.push_back(ofPoint(321, 211));
        points.push_back(ofPoint(412, 215));
        points.push_back(ofPoint(469, 167));
        points.push_back(ofPoint(483, 257));
        points.push_back(ofPoint(424, 360));
        points.push_back(ofPoint(286, 353));
        points.push_back(ofPoint(302, 279));
        points.push_back(ofPoint(206, 231));
    }
    
    triangles.push_back(ofVec3f(0, 1, 2));
    triangles.push_back(ofVec3f(1, 2, 3));
    triangles.push_back(ofVec3f(1, 3, 4));
    triangles.push_back(ofVec3f(3, 4, 5));
    triangles.push_back(ofVec3f(3, 5, 6));
    
    triangles.push_back(ofVec3f(6, 3, 2));
    triangles.push_back(ofVec3f(6, 8, 7));
    triangles.push_back(ofVec3f(7, 8, 9));
    triangles.push_back(ofVec3f(9, 8, 2));
    triangles.push_back(ofVec3f(0, 9, 2));


    
    
    
    
    
    generateColors();
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPushMatrix();
    ofTranslate(235, 149);
    
    if (saveScreen){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf");
    }
    

    for (int i = 0; i < triangles.size(); i++) {
        ofSetColor(colors.at(i % colors.size()));
        ofTriangle(points.at(triangles.at(i).x), points.at(triangles.at(i).y), points.at(triangles.at(i).z));
    }
    
    // I picked this color out specifically. It doesn't change like the others
    ofColor accent;
    accent.setHsb(37.54, 255*.60, 255*.75);
    ofSetColor(accent);
    ofTriangle(points.at(6), points.at(8), points.at(2));
    
    if (saveScreen){
        ofEndSaveScreenAsPDF();
        saveScreen = false;
    }
    
    ofPopMatrix();
    
}

// I settled on using a monochromatic color scheme
// by adjusting the brightness randomly between 29% and 94%.
// TODO: expand this to create different schemes
void testApp::generateColors(){
    
    colors.clear();
    
    for (int i = 0; i < numColors; i++) {
        ofColor color;
        
        color.setHsb(myHue, 255, ofRandom(255*.29,255*.94));
        colors.push_back(color);
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if (key == 101){            // if 'e' pressed, export points
        
        for (int i = 0; i < points.size(); i++){
            ofLogNotice() << points.at(i);
        }
        
    } else if (key == 99){      // 'c' to generate new colors
        generateColors();
    } else if (key == 357) {    // 'up' to move hue clockwise
        myHue++;
        ofLogNotice() << myHue;
        generateColors();
    } else if (key == 359) {    // 'down' to move hue counterclockwise
        myHue--;
        ofLogNotice() << myHue;
        generateColors();
    } else if ( key == 97){     // 'a' to check smoothing disabled
        ofDisableSmoothing();
    } else if (key == 115){     // 's' save pdf
        saveScreen = true;
    } else {
        ofLogNotice() << key;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    if (debug){
        points.at(currentPoint).set(x, y);
    }

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    if (debug){
        points.at(currentPoint).set(x, y);
        currentPoint++;
        
        if (currentPoint >= points.size()){
            currentPoint = 0;
        }
    }
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
