//
//  Grid.hpp
//  emptyExample
//
//  Created by Lina  Sarma on 03/01/17.
//
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "Cell.hpp"
#include "ofMain.h"
#include "Chromosome.hpp"
class Grid{
    
    
public:
    
    
   Grid();
    

 

    void drawGrid(vector< vector<int> > newTemp,    ofColor color,
                  ofColor color2, ofColor color3, ofColor color4, int x, int y);
    
    vector<Cell>c;
    vector< vector<int> > newTemp;
    int cellSize;
    int numCols;
    int numRows;
    int height;
    int cellWidth;
    int cellHeight;
    int width;
    
};



#endif /* Grid_hpp */
