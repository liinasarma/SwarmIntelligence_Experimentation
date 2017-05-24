//
//  Chromosome.cpp
//  NaturalComputing CWK
//
//  Created by Lina  Sarma on 28/12/16.
//

#include "Chromosome.hpp"
#include "SDS.hpp"

#include <stdio.h>
#include <vector>

#include "ofMain.h"
Chromosome::Chromosome()
{
    
    posx = 0;
    posy = 0;
    //  texScreen.allocate(480,480,GL_RGB);
    
    int popSize = 200;
    index =0;
    string symmetries[] = {h,v};
    
    
    for(int i = 0; i<popSize; i++){
        
        ag.push_back(Agent());
        
        
    }
    
    
    
    for(int i = 0; i<ag.size(); i++){
        
        ag.at(i).setStatus(false);
        
        
    }
    
    for(int i = 0; i<popSize; i++){
        
        
        
        ag.at(i).setHypoX((int)ofRandom(3,26));
        ag.at(i).setHypoY((int)ofRandom(3,26));
        
    }
    
    
    
    for(int i = 0; i < 30; i++)
    {
        vector<int> temp; // create an array, don't work directly on buff yet.
        for(int j = 0; j < 30; j++)
            temp.push_back(i);
        
        genes.push_back(temp); // Store the array in the buffer
    }

    
    
    for(vector<vector<int> >::iterator it = genes.begin(); it != genes.end(); ++it)
    {
        //it is now a pointer to a vector<int>
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            // jt is now a pointer to an integer.
            
            int random = (int)ofRandom(5);
            *jt = random;
           
        }
 
        
    }
    

    
    
    //  display();
    
}


void Chromosome::testPhase(vector< vector<int> > genes2){
    
    
    
    if(index<40){
        
        active = true;
        
    }
    
    
    else{
    
        active = false;
    }
    
    
    if(active){
        index++;
    
        
    // Test Phase
        
    for ( int i = 0; i < ag.size(); i++ ){ //loop through the available agents
        
        
        
        string s =(symmetries[int(ofRandom(0,2))]);
        
        int currentHypoX = ag.at(i).getHypoX(); //retrieve their hypothesis
        int currentHypoY = ag.at(i).getHypoY();
        
        int count = 0;
        
        int x = currentHypoX; // row
        int y = currentHypoY; // col

        
        
        
        int rCol = (int)ofRandom(4); // columns
        int rRow= (int)ofRandom(2); // rows
        
        int rRowComp = -1;
        
        if (rRow == 0)
            rRowComp = 3;
        else
            rRowComp = 2;
        
        int index1 = genes.at(x+rRow).at(y+rCol);
        int index2 = genes.at(x+rRowComp).at(y+rCol);
        
        if(index1 == 0 && index2 == 3){
            
            count++;
        }
        else if(index1 == 3 && index2 == 0){
            
            count++;
        }
        else if(index1 == 1 && index2 == 2){
            
            count++;
        }
        else if(index1 == 2 && index2 == 1){
            
            count++;
        }

            if(count==1){
            
            
            ag.at(i).setStatus(true);
            
            }
        
        
        else{
            
            ag.at(i).setStatus(false);
            
        }
        
    }

    
     


    
    
                    for ( int i = 0; i < ag.size(); i++ )
    
                    {
    
    
    
    
                        if (ag.at(i).getStatus() == false)//if the agent chosen is false
                        {
                            int random = (int)ofRandom(199);  //choose another random agent as long as it is in the boundary of agents
    
                            if ( ag.at(random).getStatus() == true) //if the randomly chosen agent is true take its hypothesis
                            {
    
                                ag.at(i).setHypoX(ag.at(random).getHypoX());
                                ag.at(i).setHypoY(ag.at(random).getHypoY());
    
    
                            }
    
    
                            else
                            {
    
                                int rand2 = (int)ofRandom(3,26);  //if the randomly chosen agent is not true choose a random hypothesis
                                int rand3 = (int)ofRandom(3,26);
                                ag.at(i).setHypoX(rand2);
                                ag.at(i).setHypoY(rand3);
    
                            }
    
                        }
    
    
                    }
        
        

        for(int i = 0; i<ag.size();i++){
            if(ag.at(i).getStatus() == true){
                
                
                xpos = ag.at(i).getHypoX();
                ypos = ag.at(i).getHypoY();
                
            
                
                
            }
        }
    
    
    
    
    int final_frequency = 0;
    int local_frequency = 0;
 
    
        if(index ==39){
    for(int i = 0; i<ag.size()-1; i++){
        if(ag.at(i).getHypoX() == ag.at(i+1).getHypoX()){
         if(ag.at(i).getHypoY() == ag.at(i+1).getHypoY()){
            local_frequency++;
            
         }
        }else{
        
        
         local_frequency = 0;
        
        }
        if (local_frequency > final_frequency)
        {
            final_frequency = local_frequency;
            
            
            collectRow.push_back(ag.at(i).getHypoX());
            collectCol.push_back(ag.at(i).getHypoY());
            

            posx = collectRow.at(collectRow.size()-1);
            posy = collectCol.at(collectCol.size()-1);

            
        }
    

    }
    }
    }
    


    

    
    }














