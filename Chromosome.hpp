//
//  Chromosome.hpp
//
//  Created by Lina  Sarma on 28/12/16.
//
//

#ifndef Chromosome_hpp
#define Chromosome_hpp

#include <stdio.h>
#include <vector>
#include "SDS.hpp"
#include <string>
#include "ofMain.h"
class Chromosome{
    

    
public:
//    int currCol;
//    int currRow;
    int index;
    int posx;
    int posy;

vector< vector<int> > genes;
   
//vector<float> gene;

    Chromosome();
    int currCol;
    static int col;
    static int row;
    int currRow;
  vector<Agent> ag;
    int numCols;
    int numRows;
    int cellWidth;
    int cellHeight;
    bool iterate;

    string h = "horizontal";    //defines YELLOW
    string v = "vertical";
    string symmetries[2];           //random selects one of above color
    
    
   ofTexture texScreen;
   void getX(int row);
   void getY(int col);
    
   void draw(vector< vector<int> > genes, int posx, int posy);
     void testPhase(vector< vector<int> > genes2);
    bool active;
   vector< vector<int> > g;
    vector<int> collectRow;
    vector<int> collectCol;
   
    vector< vector<int> > next;
    
 
    void expand();
    
    int ind;
    int agentIndex;
    int getIndex();
    void setIndex(int ind);
    int xpos;
    int ypos;
    
};






#endif /* Chromosome_hpp */
