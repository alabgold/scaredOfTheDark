#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    int num = 1000;
    p.assign(num, particle());
    
    makeParticles();
    cam.initGrabber(1024,768);

    
    colorImg.allocate(1024,768);
    grayImage.allocate(1024,768);
    
    ghost.load("whiteghost.png");
    pumpkins.load("background.png");
    
    mySound.load("creepy.mp3");
    mySound.setLoop(true);
    mySound.play();
    
    
}

//--------------------------------------------------------------
void ofApp::makeParticles(){
    repelPoints.clear();
    for(int i = 0; i < 4; i++){
        repelPoints.push_back( ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) ) );
    }
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].reset();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    int w = cam.getWidth();
    int h = cam.getHeight();
    
    maxBrightness  = 0;
    oldMaxBrightness  = 0;
    
    maxBrightnessX = 0;
    maxBrightnessY = 0;
    
    for (int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            ofColor colorAtXY = cam.getPixelsRef().getColor(x, y);
            float brightnessOfColorAtXY = colorAtXY.getBrightness();
            if (brightnessOfColorAtXY > maxBrightness){
                maxBrightness = brightnessOfColorAtXY;
                maxBrightnessX = x;
                maxBrightnessY = y;
            }
        }
    }
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setXY(maxBrightnessX, maxBrightnessY);
        p[i].update();
    }

    bool bNewFrame = false;
    cam.update();
    
    bNewFrame = cam.isFrameNew();
    if (bNewFrame){
        colorImg.setFromPixels(cam.getPixels());
        
    }
    grayImage = colorImg;
  
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    grayImage.draw(grayImage.getWidth(),0,-grayImage.getWidth(),grayImage.getHeight());
    ofEnableAlphaBlending();
    pumpkins.draw(0,350);
    ofDisableAlphaBlending();
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    }

    
    ofSetColor(190);
    
    //    DEBUG
        ofNoFill();
        ofDrawCircle(1028-maxBrightnessX, maxBrightnessY, 10);
  
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
