int w;
int columns;
int rows;
int[][] rightGrid;
int gridSize = 24;
int[][] next;
int rules = 1;

void setup() {
  size(800, 800);
  w = 8;
  // Calculate columns and rows
  columns = floor(width/w);
  rows = floor(height/w);
  
  
    rightGrid = new int[rows][columns];
  next = new int[rows][columns];
  // Wacky way to make a 2D array is JS
for (int row = 0; row<rows; row++ ) {
    for (int col = 0; col<columns; col++) {
      rightGrid[row][col] = 0;
    }
  }

  //inserting empty cell in the left grid 
  for (int row = 0; row<rows; row++ ) {
    for (int col = 0; col<columns; col++) {
      next[row][col] = 0;
    }
  }
   init();
}

void draw() {
  background(255);
noStroke();
  generate();
  for ( int i = 0; i < rows;i++) {
    for ( int j = 0; j < columns;j++) {
      if ((rightGrid[i][j] == 0)) fill(255);
      else if(rightGrid[i][j] == 1){
        fill(0);}
        else if(rightGrid[i][j] == 2){
        
        fill(255,0,0);
        }  else if(rightGrid[i][j] == 3){
        
        fill(0,255,0);
        } else if(rightGrid[i][j] == 4){
        
        fill(0,0,255);
        }
        

      rect(i*w, j*w, w-1, w-1);
    }
  }

}

// reset rightGrid when mouse is pressed
void mousePressed() {
  init();
}

// Fill rightGrid randomly
void init() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j <columns; j++) {
   rightGrid[i][j] = 0;
 
    }
  }
  rightGrid[rows/2][columns/2] = 1;
}

// The process of creating the new generation
void generate() {

  // Loop through every spot in our 2D array and check spots neighbors
  for (int x = 1; x < rows - 1; x++) {
    for (int y = 1; y < columns - 1; y++) {
      // Add up all the states in a 3x3 surrounding grid
      int neighbors = 0;
      
      //Moore neighborhood
      //for (int i = -1; i <= 1; i++) {
      //  for (int j = -1; j <= 1; j++) {
      //    neighbors += rightGrid[x+i][y+j];
      //  }
      //}
        neighbors += rightGrid[x-1][y];
      neighbors += rightGrid[x+1][y];
      neighbors += rightGrid[x][y-1];
      neighbors += rightGrid[x][y+1];

      // subtract the current cell's state 
      neighbors -= rightGrid[x][y];
//Rules
     
      if (rules == 1) {

        if ((rightGrid[x][y] == 0) && (neighbors ==3 || neighbors==1)) {
         rightGrid[x][y] = 1;
        } else if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
         rightGrid[x][y] = 2;
        } else if ((rightGrid[x][y] == 3 || rightGrid[x][y]==2) && (neighbors ==1 || neighbors ==3)) {
         rightGrid[x][y] = 3;
        } else if ((rightGrid[x][y] == 1 || rightGrid[x][y]==2) && (neighbors ==2 || neighbors ==3)) {
         rightGrid[x][y] = 4;
        }


      
     } else if (rules == 2) {


        if ((rightGrid[x][y] == 0) && (neighbors ==3 || neighbors==1)) {
            rightGrid[x][y] = 1;
          }  if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
            rightGrid[x][y] = 2;
           } else if ((rightGrid[x][y] == 3 || rightGrid[x][y]==2) && (neighbors ==1)) {
            rightGrid[x][y] = 3;
           } else if ((rightGrid[x][y] == 1 || rightGrid[x][y]==2) && (neighbors ==3)) {
            rightGrid[x][y] = 4;
           }
      } 
      
     else if (rules==3) {

        if ((rightGrid[x][y] == 0) && (neighbors==1)) {
         rightGrid[x][y] = 1;
        }  
        if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
         rightGrid[x][y] = 2;
        } else if ((rightGrid[x][y] == 0 ) && (neighbors ==3)) {
         rightGrid[x][y] = 3;
        } else if ((rightGrid[x][y] == 0) && (neighbors ==4)) {
         rightGrid[x][y] = 4;
        } else if ((rightGrid[x][y] == 3 ||rightGrid[x][y] == 4 ) && (neighbors ==7 || neighbors ==8)) {
         rightGrid[x][y] = 3;
        }

      } else if (rules == 4) {

        if ((rightGrid[x][y] == 0) && (neighbors ==1)) {

          rightGrid[x][y] = 3;
        } else if ((rightGrid[x][y] == 1) && (neighbors ==2 || neighbors ==3)) {
          rightGrid[x][y] = 4;
        } else if ((rightGrid[x][y] == 2) && (neighbors ==2)) {
          rightGrid[x][y] = 2;
        } else if ((rightGrid[x][y] == 4 || rightGrid[x][y]==0) && (neighbors==4||neighbors ==2 || neighbors ==3)) {

          rightGrid[x][y] = 3;
        }
      } else if (rules == 5) {
        if ((rightGrid[x][y] == 0) && (neighbors ==6)) {

          rightGrid[x][y] = 3;
        } else if ((rightGrid[x][y] == 0) && (neighbors ==7)) {

          rightGrid[x][y] = 1;
        } else if ((rightGrid[x][y] == 0) && (neighbors ==4)) {

          rightGrid[x][y] = 2;
        } else if ((rightGrid[x][y] == 0) && (neighbors ==3)) {

          rightGrid[x][y] = 4;
        } else if (( rightGrid[x][y]==4) && (neighbors ==2 )) {
          rightGrid[x][y] = 3;
        } else if (( rightGrid[x][y]==3) && (neighbors ==4 )) {
          rightGrid[x][y] = 1;
        } 



      }

    }
  }

  //// Swap!
  //int[][] temp = rightGrid;
  //rightGrid = next;
  //next = temp;
}