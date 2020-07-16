//
//  Distortion.hpp
//  AudioOOP
//
//  Created by Jerry Bennett on 2/6/20.
//  Copyright © 2020 Jerry Bennett. All rights reserved.
//

#ifndef Distortion_hpp
#define Distortion_hpp

#include <cmath>
#include <vector>
using namespace std;
//#include <stdio.h>

class Tremolo{
public:
    
    //constructor funtion (special funtion with no return type)
    //name is equal to the class name
    Tremolo();
    
    //Tremolo(float drive);
    
    //destructor
    ~Tremolo();
    
    enum LFOType{ sinewave, squarewave };
    
    void processSignal(vector<float> & signal, int numSamples);
    
    float processSample(float x);
    
    void setFs(float Fs);
    void setSpeed(float speed);
    void setDepth(float depth);
    
    LFOType lfoSelector = sinewave;
    
private:
    
    float Fs = 48000.f;
    
    float speed = 1.0f; //Hz, frequency of LFO
    float depth = 100.0f; //percent of intensity, control amplitude of lfo
    
    float amp = depth/200.f;
    float offset = 1.f - amp;
    
    //lfo parameters
    float currentAngle = 0.0f;
    float angleChange = speed * (1.f/Fs) * 2*M_PI;
    
    //LFOType lfoSelector = sinewave;
};
#endif /* Distortion_hpp */
