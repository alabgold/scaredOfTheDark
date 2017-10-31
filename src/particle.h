#pragma once
#include "ofMain.h"

// particle.cpp and particle.h adapted from ofMathParticle_Brightestpx by alexmargineanu
// https://github.com/alexmargineanu/ofMathParticle_Brightestpx

class particle{
    
public:
    particle();
    
    void setXY(int newX, int newY);
    void setRepelPoints( vector <ofPoint> * attract );
    
    void reset();
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    int myX;
    int myY;
    
    vector <ofPoint> * repelPoints;
    ofImage ghost;
};
