//
//  Particle.hpp
//  oFFinalCCLab
//
//  Created by  Christine on 12/1/15.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#endif /* Particle_hpp */

#include "ofMain.h"

class Particle {
public:
    
    void setup();
    void draw();
    void update();
    
    ofVec3f pos,vel,acc,oldpos;
    float angle;
    ofColor color;
    int age;
    
    
};