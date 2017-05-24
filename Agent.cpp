//
//  Agent.cpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 18/01/17.
//
//

#include "Agent.hpp"

//Agent class holds all the variables for the agents searching the grod for symmetry

Agent::Agent(){
    

}
//sets the initial hypothesis/location of X
void Agent::setHypoX(int hypoX)
{
    hypothesisX = hypoX; //return the agents hypothesis(column)
    
    
   //cout<<hypothesisX<<endl;
}

//returns the initial hypothesisX for testing and further use to be shared among other members
int Agent::getHypoX(){
    
    
    return this ->hypothesisX;
    
}

//sets the agents Y hypothesis and saves them in the variable

void Agent::setHypoY(int hypoY)
{
    hypothesisY = hypoY;
}

//returns the agents hypothesisY so that it can be retrieved when necessary
int Agent::getHypoY(){
    
    
    return this ->hypothesisY;    //get the selected agents hypothesis(column)
    
}

// save the status after it has been retrieved to keep track of which hypthesis are true
//retrieve it when necessary
void Agent::setStatus( bool s )
{
    status = s;         //set status so that we know when symmetrical
}
bool Agent::getStatus()
{
    
    return status;//returns the status if symmetrical
}






