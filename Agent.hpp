//
//  Agent.hpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 18/01/17.
//
//

#ifndef Agent_hpp
#define Agent_hpp

#include <stdio.h>
#include "ofMain.h"
class Agent{
    
    
public:
    
    Agent();
    Agent(vector<Agent> *a);
    int state;
    bool status;
    int hypothesisX;
    int hypothesisY;
    int numCols;
    int hypoX;
    int hypoY;
    int getHypoX();
    int getHypoY();
    int _row1;
    int _row2;
    bool getStatus();
    void setHypoX( int hypoX );
     void setHypoY( int hypoY );
    void setRow1(int _row1);
    void setRow2(int _row2);
    int row1();
    int row2();
    void setStatus( bool s );
    vector<Agent> ag;
    
};



#endif /* Agent_hpp */
