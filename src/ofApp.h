#pragma once

#include "ofMain.h"
#include "particle.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void makeParticles();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    string currentModeStr;
    
    vector <particle> p;
    vector <ofPoint> repelPoints;
    vector <ofPoint> repelPointsWithMovement;
    
    ofVideoGrabber cam;
    
    int   maxBrightnessX;
    int   maxBrightnessY;
    float maxBrightness;
    float oldMaxBrightness;
    
    ofxCvColorImage			colorImg;
    ofxCvGrayscaleImage 	grayImage;
    
    ofImage pumpkins;
    ofImage ghost;

    ofSoundPlayer   mySound;
    // music by bensound.com
    
    
};
