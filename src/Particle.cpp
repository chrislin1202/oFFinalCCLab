//
//  Particle.cpp
//  oFFinalCCLab
//
//  Created by  Christine on 12/1/15.
//
//

#include "Particle.hpp"


void Particle::setup() {
    
    vel.x = 2*ofRandomf();
    vel.y = 2*ofRandomf();
    vel.z = 2*ofRandomf();
    angle = ofRandomf()*TWO_PI;
    age = 0;
}

void Particle::draw() {
    ofSetColor(color,ofMap(age,0,20,255,0,true));
//    ofLine(oldpos,pos);
    ofDrawCircle(pos.x, pos.y, 16);
    
    
}

void Particle::update() {
    
    angle += ofSignedNoise(pos.x, pos.y)*TWO_PI;
    vel.rotate(0,0,angle);
    oldpos = pos;
    pos += vel;
    age+=1;
}