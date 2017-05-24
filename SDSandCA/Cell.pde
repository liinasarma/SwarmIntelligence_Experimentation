class Cell{
    int cellSize;
    int numCols;
    int numRows;
    int height;
    int cellWidth;
    int cellHeight;
    int width;
    
    Cell(){
    
    
    
    
    }
    
    void display(int[][] newTemp, color color1, color color2, color color3, color color4)
{
    

    
    //iterate through the patern array
    //and draw a triangle depending on the number in the cell
    for(int row=0; row<gridSize-2; row++){
        
        for(int col = 0; col < gridSize-2; col++)
        {

            
            if(newTemp[row][col]==0){
                
                
              fill(0);
                
                
                
            }
             if(newTemp[row][col]==1){
                
               
               
                
                fill(0);
                triangle(col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
            }
            else if(newTemp[row][col]==2){
                
                
                color(255,0,0);
                triangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth);
            }

            else if(newTemp[row][col]==3){
                
                
                color(0);
                triangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
            }
           else if(newTemp[row][col]==4){
                
                
                triangle(col*cellWidth, row*cellHeight, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth, row*cellWidth+cellWidth);
               
            }
              
            
        }
       
    }
    

    
}

    
}