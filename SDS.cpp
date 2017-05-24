//
//  SDS.cpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 13/01/17.
//
//

#include "SDS.hpp"
#include "Agent.hpp"
#include "Cell.hpp"
#include "Chromosome.hpp"
/*
SDS::SDS(){
    
    
    
    agents = true;

    ag.resize(4);

    ssSize = l.size();
    //create 4 agents, each one assigned a hypothesis corresponding to its column
    for(int i = 0; i<4; i++){
        
        ag.push_back(Agent(i));
        
    }
    


}

void SDS::testPhase(){

    
    //temporaray vector holds what we ahve produced in our chromosome
    //vector< vector<int> > l = g[0].display();
    //set the size of the first vector so that we know the boundary of the rows
    
    if(agents==true){
        for(int m = 0; m<20;m++){
            int x=0, y=0, x1=0, y1=0;
            
            vector< vector<int> > l = cr[m].draw();
            ssSize = l.size();
            //iterate through all the agents and set the hypothesis of the agent
            for ( int i = 0; i < 4; i++ ){
                
                
                //set the hypothesis of the agent
                ag[i].setHypo(i);
                
                
                //get the hypothesis, number of the cell and use it to define the x value
                int currentHypo = ag[i].getHypo();
                int random = rand()%3;
                int random2 = rand()%3;
                
                
                x = currentHypo;//current column
                y = random; //random from 1 to 4 rows
                
                
                x1 = x; //the same column
                
                
                //set the other y value so that we are looking for symmetry
                //in every second row
                
                
                if(y ==3){
                    
                    y1 = 1;
                }
                if(y == 2){
                    
                    y1 = 0;
                    
                }
                if(y ==0){
                    y1 = 2;
                    
                }
                if(y ==1){
                    y1 = 3;
                    
                }
                
                
                //if the random rows correspond, set the agents status as true
                //and add count to the current agents
                
                if ( l[y1][x1] == l[y][x] )
                {
                    
                    
                    
                    ag[i].setStatus(true);
                    
                    // activeAgents[currentHypo] = activeAgents[currentHypo] + 1;
                }
                else
                {
                    
                    
                    ag[i].setStatus(false);
                    
                    
                }
            }
        }
        
        








}

     */   



