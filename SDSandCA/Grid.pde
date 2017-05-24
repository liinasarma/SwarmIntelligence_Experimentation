class Grid {

  //Cell c = new Cell();
  int cellSize;
  int numCols;
  int numRows;
  int height;
  int cellWidth = 10;
  int cellHeight = 10;
  int width;
  int variation = 1;

  Grid() {
  }



  void drawGrid(int[][] newTemp, color color1, color color2, color color3, color color4, int posx, int posy, 
  int cellWidth, int ellipseShift, int rules, int gridSize, float scaleVar )
  {





    //iterate through the patern array
    //and draw a triangle depending on the number in the cell

    pushMatrix();
    translate(posx, posy);
    scale(1);
    for (int row=1; row<gridSize-1; row++) {

      for (int col = 1; col < gridSize-1; col++)
      {

        if (newTemp[row][col]==0) {

          fill(255);
        } else if (newTemp[row][col]==1) {

          fill(color2);
          triangle(col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
        } else if (newTemp[row][col]==2) {


          fill(color3);
          triangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth);
        } else if (newTemp[row][col]==3) {


          fill(color4);
          ellipseMode(CENTER);
         // ellipse(col*cellWidth+ellipseShift, row*cellWidth+ellipseShift, cellWidth, cellWidth);


          triangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth+cellWidth, col*cellWidth, row*cellWidth+cellWidth);
        } else if (newTemp[row][col]==4) {

          fill(color1);
           triangle(col*cellWidth, row*cellWidth, col*cellWidth+cellWidth, row*cellWidth, col*cellWidth, row*cellWidth+cellWidth);
          ellipseMode(CENTER);
         // ellipse(col*cellWidth+ellipseShift, row*cellWidth+ellipseShift, cellWidth, cellWidth);
        }
      }
    

    
   
}
 popMatrix();
}

}
  