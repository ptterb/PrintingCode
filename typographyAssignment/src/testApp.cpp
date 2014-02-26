#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    bRecord = false;
    
    barWidth = 20;
    baseUnit = 25;
    start = 0;
    
    
    
    //Gap
    vector<vector<ofVec2f> > gapBar;
    vector<ofVec2f> gapBar1;
    gapBar1.push_back(ofVec2f(start, baseUnit * 7));
    gapBar.push_back(gapBar1);
    
    // Letter F
    vector<vector<ofVec2f> > f;
    
    vector<ofVec2f> f1;
    f1.push_back(ofVec2f(start, baseUnit));
    f1.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    vector<ofVec2f> f2;
    f2.push_back(ofVec2f(start, baseUnit));
    f2.push_back(ofVec2f(baseUnit * 2, baseUnit));
    f2.push_back(ofVec2f(baseUnit * 4, baseUnit * 3));
    
    vector<ofVec2f> f3;
    f3.push_back(ofVec2f(start, baseUnit));
    f3.push_back(ofVec2f(baseUnit * 2, baseUnit));
    f3.push_back(ofVec2f(baseUnit * 4, baseUnit * 3));
    
    f.push_back(f1);
    f.push_back(f2);
    f.push_back(f3);

    // Letter U
    vector<vector<ofVec2f> > u;
    
    vector<ofVec2f> u1;
    u1.push_back(ofVec2f(start, baseUnit));
    u1.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    vector<ofVec2f> u2;
    u2.push_back(ofVec2f(start, baseUnit * 5));
    u2.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    vector<ofVec2f> u3;
    u3.push_back(ofVec2f(start, baseUnit));
    u3.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    u.push_back(u1);
    u.push_back(u2);
    u.push_back(u3);
    
    // Letter T
    vector<vector<ofVec2f> > t;
    
    vector<ofVec2f> t1;
    t1.push_back(ofVec2f(start, baseUnit));
    t1.push_back(ofVec2f(baseUnit * 2, baseUnit * 5));
    
    vector<ofVec2f> t2;
    t2.push_back(ofVec2f(start, baseUnit));
    t2.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    
    vector<ofVec2f> t3;
    t3.push_back(ofVec2f(start, baseUnit));
    t3.push_back(ofVec2f(baseUnit * 2, baseUnit * 5));
    
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
    
    // Letter R
    vector<vector<ofVec2f> > r;
    
    vector<ofVec2f> r1;
    r1.push_back(ofVec2f(start, baseUnit));
    r1.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    vector<ofVec2f> r2;
    r2.push_back(ofVec2f(start, baseUnit));
    r2.push_back(ofVec2f(baseUnit * 2, baseUnit));
    r2.push_back(ofVec2f(baseUnit * 4, baseUnit * 3));
    
    
    vector<ofVec2f> r3;
    r3.push_back(ofVec2f(start, baseUnit));
    r3.push_back(ofVec2f(baseUnit * 3, baseUnit));
    r3.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    r.push_back(r1);
    r.push_back(r2);
    r.push_back(r3);
    
    // Letter E
    vector<vector<ofVec2f> > e;
    
    vector<ofVec2f> e1;
    e1.push_back(ofVec2f(start, baseUnit));
    e1.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    vector<ofVec2f> e2;
    e2.push_back(ofVec2f(start, baseUnit));
    e2.push_back(ofVec2f(baseUnit * 2, baseUnit));
    e2.push_back(ofVec2f(baseUnit * 4, baseUnit));
    e2.push_back(ofVec2f(baseUnit * 6, baseUnit));

    
    
    vector<ofVec2f> e3;
    e3.push_back(ofVec2f(start, baseUnit));
    e3.push_back(ofVec2f(baseUnit * 2, baseUnit));
    e3.push_back(ofVec2f(baseUnit * 4, baseUnit));
    e3.push_back(ofVec2f(baseUnit * 6, baseUnit));
    
    e.push_back(e1);
    e.push_back(e2);
    e.push_back(e3);

    
    
    letters.push_back(gapBar);
    letters.push_back(f);
    letters.push_back(gapBar);
    letters.push_back(u);
    letters.push_back(gapBar);
    letters.push_back(t);
    letters.push_back(gapBar);
    letters.push_back(u);
    letters.push_back(gapBar);
    letters.push_back(r);
    letters.push_back(gapBar);
    letters.push_back(e);
    letters.push_back(gapBar);

    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (bRecord){
        ofBeginSaveScreenAsPDF("FUTURE.pdf");
    }
    
    //background.draw(0, 0);
    ofBackground(25);
    
    hPos = 0;
    
    ofTranslate(ofGetWidth()/4, ofGetHeight()/3);
    
    for (int h = 0; h < letters.size(); h++) {
        for (int i = 0; i < letters[h].size(); i++){
            
            ofTranslate(0,-9);
            
            for (int j = 0; j < letters[h][i].size(); j++){
                ofVec2f currentBar = letters[h][i].at(j);
                ofRotateZ(20);
                ofSetColor(50);
                ofRect(hPos, currentBar.x, barWidth, currentBar.y);
                ofRotateZ(-20);
                ofSetColor(255);
            }
            
            hPos += barWidth + 5;
            
        }
    }
    
    if (bRecord){
        ofEndSaveScreenAsPDF();
        bRecord = false;
        
    }
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    bRecord = true;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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
