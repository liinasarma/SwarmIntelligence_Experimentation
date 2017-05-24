//
//  Cell.cpp
//  NaturalComputingCWK
//
//  Created by Lina  Sarma on 08/01/17.
//
//

#include "Cell.hpp"

Cell::Cell()
{
   
    numCols = 24;
    numRows = 24;
    cellWidth = 20;
    cellHeight = 20;
    cellSize = 20;
    height = 480;
    width = 480;
    
    
    
}
void Cell::display(vector< vector<int> > newTemp, ofColor color, ofColor color2, ofColor color3, ofColor color4)
{
    

    
    //iterate through the patern array
    //and draw a triangle depending on the number in the cell
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
    

    
}


