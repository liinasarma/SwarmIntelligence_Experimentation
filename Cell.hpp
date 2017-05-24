//
//  Cell.hpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 08/01/17.
//
//

#ifndef Cell_hpp
#define Cell_hpp

#include "ofMain.h"
#include <stdio.h>

class Cell{
    
    
public:
    vector< vector<int> > newTemp;
    Cell();
    
    int state;
    
    
    void display(vector< vector<int> > newTemp, ofColor color,ofColor color2, ofColor color3, ofColor color4 );
    

    int cellSize;
    int numCols;
    int numRows;
    int height;
    int cellWidth;
    int cellHeight;
    int width;
    };



#endif /* Cell_hpp */
