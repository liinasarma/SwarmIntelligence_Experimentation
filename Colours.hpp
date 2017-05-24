//
//  Colours.hpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 07/02/17.
//
//

#ifndef Colours_hpp
#define Colours_hpp

#include <stdio.h>
#include <stdio.h>
#include "Cell.hpp"
#include "ofMain.h"
#include "Chromosome.hpp"
class Colours{
    
    
public:
    
    
    Colours();
    
    
    
    ofColor complementaryCol(ofColor col1);
    ofColor tertiaryCol(ofColor col1);



    
    float k;
    float cMax;
    float cMin;
    float r;
    float b;
    float g;
    float tempR;
    float tempB;
    float tempG;
    float temp1;
    float temp2;
    
    ofColor col2;
    
    float _h,_s,_l,_r,_g,_b;
    
};


#endif /* Colours_hpp */
