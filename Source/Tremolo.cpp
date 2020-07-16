//
//  Distortion.cpp
//  AudioOOP
//
//  Created by Jerry Bennett on 2/6/20.
//  Copyright © 2020 Jerry Bennett. All rights reserved.
//

#include "Tremolo.hpp"
//constructor funtion (special funtion with no return type)
//name is equal to the class name
Tremolo::Tremolo(){
    //no need to do anything with default constructor
}

//Tremolo::Tremolo(float drive){
//    this->drive = drive;
//}

//destructor
Tremolo::~Tremolo(){
    //cout << "Destoructor called" << endl;
}

void Tremolo::processSignal(vector<float> & signal, int numSamples){
       //where we do the effect
       for (int n = 0; n < numSamples; n++){
           float x = signal[n];
           //signal[n] = (2.0f/M_PI) * atan(drive * x);
           signal[n] = processSample(x);
       }
}

float Tremolo::processSample(float x){
    
    float lfo;
    switch(lfoSelector){
        case sinewave:
            lfo = amp * sin(currentAngle) + offset;
            break;
            
        case squarewave:
            if (currentAngle < M_PI){
                lfo = amp * 1 + offset;
            }else{
                lfo = 1.0f - amp * 2.0f;
            }
            break;
        default:
            lfo = amp * sin(currentAngle) + offset;
    }
    
    currentAngle += angleChange;
    if(currentAngle > 2.f * M_PI){
        currentAngle -= 2 * M_PI;
    }
    
    return x * lfo;
    
}

void Tremolo::setFs(float Fs){
    if(speed >= 0.1f && speed <= 10.0f){
        this->Fs = Fs;
        angleChange = speed * (1.f/Fs) * 2 * M_PI;
    }
}
void Tremolo::setSpeed(float speed){
    if (speed >= 0.1f && speed <= 10.0f){
        this->speed = speed;
    }
}

void Tremolo::setDepth(float depth){
    if(depth >= 0.0f && depth <= 100.0f){
        this -> depth = depth;
        amp = depth/200.0f;
        offset = 1.0f-amp;
    }
}
//void Distortion::setDrive(float drive){
//    if(drive >= 1.0f && drive <= 10.0f){
//        this->drive = drive;
//    }
//}
