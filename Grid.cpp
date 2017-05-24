//  Grid.cpp
//  emptyExample
//
//  Created by Lina  Sarma on 03/01/17.


#include "Grid.hpp"
#include "Chromosome.hpp"
#include "Cell.hpp"
Grid::Grid()
{


    
    
    c.push_back(Cell());
  //  c.push_back(Cell());
    
    
    
}

void Grid::drawGrid(vector< vector<int> > newTemp, ofColor color,ofColor color2, ofColor color3, ofColor color4, int x, int y)
{
    
    int cellWidth = 20;
    int cellHeight = 20;
    
    
    //copy(newTemp.begin(), newTemp.end(), back_inserter(newTemp2));

//    ofPushMatrix();
//    ofTranslate(x,y);
//    c[0].display(newTemp,color,color2, color3, color4);
//    ofPopMatrix();
    
//    //newTemp.clear();
//    ofPushMatrix();
//    ofTranslate(x,0);
//    c[1].display(newTemp,color,color2, color3, color4);
//    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(x,y);
    
 
    for(int row=0; row<newTemp.size(); row++){
        
        for(int col = 0; col < newTemp[row].size(); col++)
        {
            
            
            if(newTemp[row][col]==0){
                
                ofSetColor(color);
                ofDrawTriangle(col*cellWidth, row*cellHeight, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth, row*cellWidth+cellWidth);
                
            }
            if(newTemp[row][col]==1){
                
                
                ofSetColor(color2);
                ofDrawTriangle(col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
            }
            else if(newTemp[row][col]==2){
                
                
                ofSetColor(color3);
                ofDrawTriangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth);
            }
            
            else if(newTemp[row][col]==3){
                
                
                ofSetColor(color4);
                ofDrawTriangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
            }
            
            
        }
        
    }
    
    
   ofPopMatrix();
    
  
    
}




