//
//  Fly.hpp
//  emptyExample
//
//  Created by Lina  Sarma on 13/03/17.
//
//

#ifndef Fly_hpp
#define Fly_hpp

#include <stdio.h>


class Fly{



public:
    
    Fly();

    
    void setStatus(bool status);
    bool getStatus();
    
    void setPos(int pos, int pos2);
    int getPosX();
    int getPosY();
    int tempPos1;
    int tempPos2;

};

#endif /* Fly_hpp */