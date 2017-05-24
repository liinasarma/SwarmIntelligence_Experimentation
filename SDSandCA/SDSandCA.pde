
Chromosome cr = new Chromosome(2);
Chromosome cr2 = new Chromosome(4);



Grid g = new Grid();
Grid g2 = new Grid();
Grid g3 = new Grid();
Grid g4 = new Grid();
Grid g5 = new Grid();

int iterations =0;

boolean play = false;
color color3 = color(176, 102, 96);
color color4 = color(219, 173, 114);
color color2 = color(155, 175, 142);
color color1 = color(106, 125, 142);

color color5 = color(255, 0, 0);
color color6 = color(0, 0, 0);
color color7 = color(255, 0, 0);
color color8 = color(0, 0, 0);

int rules = 3;
int rules1 = 1;
int rules2 = 2;
int rules3 = 3;
int rules4 = 4;
int rules5 = 5;

int gridSize = 24;
int gridSize2 = 32;
int value;
int tempNeighbor;
int tempNeighbor2;
int popSize = 200;
int segmentSize = 4;

int size = 15;
int cellSize = 20;
int iteration = 100;
int[] id;
int nextState, state, neighbor;

boolean neighbor1 = false;
boolean neighbor2 = true;
boolean neighbor3 = false;
boolean neighbor4 = false;

Table table;

int[][] leftGrid;
int[][] rightGrid;
int[][] rightGrid2;
int[][] next;
int[][] next2;
int[][] segmentGrid;

int cellValue;
int m;
int last;



void setup() {

  size(1200, 800, P3D);
  table = loadTable("mammals.csv", "header");


  leftGrid = new int[gridSize][gridSize];
  rightGrid = new int[gridSize][gridSize];
  next = new int[gridSize][gridSize];
  segmentGrid = new int[4][4];


  rightGrid2 = new int[gridSize2][gridSize2];
  next2 = new int[gridSize2][gridSize2];

  cr2.display();




  for (int row = 0; row<gridSize; row++ ) {
    for (int col = 0; col<gridSize; col++) {
      rightGrid[row][col] = 0;
    }
  }

  //inserting empty cell in the left grid 
  for (int row = 0; row<gridSize; row++ ) {
    for (int col = 0; col<gridSize; col++) {
      next[row][col] = 0;
    }
  }
  for (int row = 0; row<gridSize2; row++ ) {
    for (int col = 0; col<gridSize2; col++) {
      rightGrid2[row][col] = 0;
    }
  }

  //inserting empty cell in the left grid 
  for (int row = 0; row<gridSize2; row++ ) {
    for (int col = 0; col<gridSize2; col++) {
      next2[row][col] = 0;
    }
  }
}


void draw() {

  background(255);
  iteration++;
  stroke(255, 0, 0);
fill(0);

textSize(14);
text("Grid displaying Symmetry Search", 150, 80);
text("Grid displaying CA Rules", 820, 80);

text("GridSize: " +gridSize, 550, 700);
text("Rules: " +rules, 550, 720);
  cr2.draw();


  noStroke();


 

  int rowCurr = cr2.posx;
  int colCurr = cr2.posy;
  print(rowCurr);

  int boundaryX = rowCurr+segmentSize;
  int boundaryY = colCurr+segmentSize;

  int secondBoundaryX = gridSize+segmentSize;
  int secondBoundaryY = gridSize+segmentSize;

  // replacing the symmetrical segment to the grid on the right
  if (rowCurr != 0) {

    for (int row = rowCurr; row<boundaryX; row++ ) {
      for (int col = colCurr; col<boundaryY; col++) {


        int k = cr2.genes[row][col]; 

        rightGrid[row][col] = k;

        stroke(255, 0, 0);
        noFill();
        strokeWeight(3);
        rect(colCurr*cellSize+50, rowCurr*cellSize+100, cellSize*segmentSize, cellSize*segmentSize);
        noStroke();

        if (k>0) {
          generate();
        }
      }
    }
  }





  g.drawGrid(cr2.genes, color1, color2, color3, color4, 50, 100, cellSize, 10, rules1, gridSize, 0.6);
  g2.drawGrid(rightGrid, color1, color2, color3, color4, 650, 100, cellSize, 10, rules1, gridSize, 0.6);
}

void mousePressed() {

  cr2.display();

  for (int row = 0; row<gridSize; row++ ) {
    for (int col = 0; col<gridSize; col++) {
      rightGrid[row][col] = 0;
    }
  }

  //inserting empty cell in the left grid 
  for (int row = 0; row<gridSize; row++ ) {
    for (int col = 0; col<gridSize; col++) {
      next[row][col] = 0;
    }
  }
  for (int row = 0; row<gridSize2; row++ ) {
    for (int col = 0; col<gridSize2; col++) {
      rightGrid2[row][col] = 0;
    }
  }

  //inserting empty cell in the left grid 
  for (int row = 0; row<gridSize2; row++ ) {
    for (int col = 0; col<gridSize2; col++) {
      next2[row][col] = 0;
    }
  }
}
void generate() {

  for (int x = 1; x < rightGrid.length - 1; x++) {
    for (int y = 1; y < rightGrid.length - 1; y++) {
      // Add up all the states in a 3x3 surrounding grid

      int neighbors = 1;
      //Moore Neighborhood
      /*     
       
       for (int i = -1; i <= 1; i++) {
       for (int j = -1; j <= 1; j++) {
       neighbors += rightGrid[x+i][y+j];
       }
       }
       
       */
      //Von Neumann Neighborhood

      neighbors += rightGrid[x-1][y];
      neighbors += rightGrid[x+1][y];
      neighbors += rightGrid[x][y-1];
      neighbors += rightGrid[x][y+1];



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
        }  
        if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
          rightGrid[x][y] = 2;
        } else if ((rightGrid[x][y] == 3 || rightGrid[x][y]==2) && (neighbors ==1)) {
          rightGrid[x][y] = 3;
        } else if ((rightGrid[x][y] == 1 || rightGrid[x][y]==2) && (neighbors ==3)) {
          rightGrid[x][y] = 4;
        }
      } else if (rules==3) {


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

          rightGrid[x][y] = 1;
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



  int[][] temp = rightGrid;
  rightGrid = next;
  next = temp;
}