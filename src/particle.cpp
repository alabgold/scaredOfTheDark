#include "particle.h"

//------------------------------------------------------------------
particle::particle(){
    repelPoints = NULL;
    ghost.load("whiteghost.png");
}

//------------------------------------------------------------------
void particle::setXY(int newX, int newY){
    myX = newX;
    myY = newY;
}

//------------------------------------------------------------------
void particle::setRepelPoints( vector <ofPoint> * repel ){
    repelPoints = repel;
}

//------------------------------------------------------------------
void particle::reset(){

    uniqueVal = ofRandom(-10000, 10000);
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    vel.x = ofRandom(-3.9, 3.9);
    vel.y = ofRandom(-3.9, 3.9);
    
    frc   = ofPoint(0,0,0);
    
    scale = ofRandom(0.5, 1.0);
    
    drag  = ofRandom(0.95, 0.998);

}

//------------------------------------------------------------------
void particle::update(){
    ofPoint attractPt(myX, myY);
    
    frc = attractPt-pos;

    float dist = frc.length();
    frc.normalize();
    
    vel *= drag;
    if( dist <200 ){
        vel += -frc * 0.9;
    }else{
        frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
        frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
        vel += frc * 0.04;
    }

    
    pos += vel;
    
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
    
}

//------------------------------------------------------------------
void particle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,50);
    
    ghost.draw(1026-pos.x, pos.y);
    ofDisableAlphaBlending();
}