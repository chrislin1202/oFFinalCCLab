#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<ZoomBlurPass>();
    
//    ofSetVerticalSync(true);
    cam.initGrabber(1280, 800);
    cam.listDevices();
    
    cam_frame.allocate(cam.getWidth(), cam.getHeight(), OF_IMAGE_COLOR);
    
//    img.loadImage("minions.jpg");
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(0);
    


}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        cam_frame.setFromPixels(cam.getPixels(), cam.getWidth(), cam.getHeight(), OF_IMAGE_COLOR);
    }

    ofSetWindowTitle(ofToString(ofGetFrameRate(),0));
    for (int i=0; i<particles.size(); i++) {
        particles[i].update();
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255);
    post.begin();
    
//    if (ofGetMousePressed()) {
//        img.draw(0,0);
//    }
//    cam.draw(0, 0);
    
    for (int i=0; i<particles.size(); i++) {
        Particle &p = particles[i];
        //p.color = img.getColor(p.pos.x,p.pos.y);
        p.draw();
    }
    
    for (int i=0; i<160; i++) {
        createParticle();
    }
    
    
    while (particles.size()>1000) {
        particles.erase(particles.begin());
    }
    post.end();

}

void ofApp::createParticle() {
    Particle p;
    p.setup();
    p.pos.set(ofRandomWidth(), ofRandomHeight());
//    p.color = img.getColor(p.pos.x,p.pos.y);
    p.color = cam_frame.getColor(p.pos.x, p.pos.y);
    
    particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='s') ofSaveFrame();
    if (key=='q') ofEnableSmoothing();
    if (key=='Q') ofDisableSmoothing();

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
    setup();


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
