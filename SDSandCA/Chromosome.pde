class Chromosome {



  Agent[] ag = new Agent[200];


  int index;
  int posx;
  int posy;

  int popSize = 200;
  int rCol; // correct
  int rRow;


  //int rRowComp = 1;
  int rColComp;

  int index1;
  int index2;

  int xpos;
  int ypos;

  //defines BLUE
  String h = "horizontal";    //defines YELLOW
  String v = "vertical";
  String[] symmetries = {            //random selects one of above colors
    h, v
  };


  boolean active = false; 

  int[][] genes;

  int _segment = 2;
  ArrayList<Integer> collectRow = new ArrayList<Integer>();
  ArrayList<Integer> collectCol = new ArrayList<Integer>();

  Chromosome(int segment) {

    _segment = segment;
    for ( int i = 0; i < popSize; i++ ) {
      ag[i] = new Agent();
    }
  }

  void display() {

    genes = new int[gridSize][gridSize];

    index = 0;

    for (int row = 1; row<gridSize-1; row++) {
      for (int col = 1; col<gridSize-1; col++) {


        genes[row][col] = (int)random(1, 5);
      }
    }


    for (int i = 0; i<popSize; i++) {

      ag[i].setStatus(false);
    }


    for (int i = 0; i<popSize; i++) {


      ag[i].setHypoX((int)random(3, gridSize-4));
      ag[i].setHypoY((int)random(3, gridSize-4)); 


    }
  }


  void draw() {


    //index determined the number of iterations 
    //the agents stop looking after the set amount



    if (index<iteration) {

      active = true;
    } else {

      active = false;
    }


    if (active) {
      index++;


      // test phase
      for ( int i = 0; i < popSize; i++ ) {


        int currentHypoX = ag[i].getHypoX();
        int currentHypoY = ag[i].getHypoY();

        int count = 0;

        int neighbors = 0;

        int x = currentHypoX; // row
        int y = currentHypoY; // col

        String s =(symmetries[int(random(0, 2))]); 



        if (s == "vertical") {
          int rCol = (int)random(4); // correct
          int rRow= (int)random(2);


          //int rRowComp = 1;
          int rColComp = -1;


          if (rCol == 1)
            rColComp = 0;
          //else
          //  rRowComp = 0;

          int index1 = genes[x+rRow][y+rCol];
          int index2 = genes[x+rRow][y+rColComp];

          //check if shapes match symmetrically
          if (index1 == 4 && index2 == 3) {

            count++;
          } else if (index1 == 3 && index2 == 4) {

            count++;
          } else if (index1 == 1 && index2 == 2) {

            count++;
          } else if (index1 == 2 && index2 == 1) {

            count++;
          }
          
          
     
          
        } else if (s=="horizontal") {


          rCol = (int)random(2); // correct
          rRow= (int)random(4);


          //int rRowComp = 1;
          rColComp = -1;


          if (rCol == 1)
            rColComp = 0;
          //else
          //  rRowComp = 0;
          
          index1 = genes[x+rRow][y+rCol];
          index2 = genes[x+rRow][y+rColComp];

          //check if shapes match symmetrically
          if (index1 == 1 && index2 == 3) {

            count++;
          } else if (index1 == 3 && index2 == 1) {

            count++;
          } else if (index1 == 4 && index2 == 2) {

            count++;
          } else if (index1 == 2 && index2 == 4) {

            count++;
          }

        }
          if (count==1) {


            ag[i].setStatus(true);
          } else {

            ag[i].setStatus(false);
          }
        }
      }






      for ( int i = 0; i < popSize; i++ )

      {




        if (ag[i].getStatus() == false)//if the agent chosen is false
        {
          int random = (int)random(199);  //choose another random agent as long as it is in the boundary of agents

          if ( ag[random].getStatus() == true) //if the randomly chosen agent is true take its hypothesis
          {

            ag[i].setHypoX(ag[random].getHypoX());
            ag[i].setHypoY(ag[random].getHypoY());
          } else
          {

            int rand2 = (int)random(3, gridSize-4);  //if the randomly chosen agent is not true choose a random hypothesis
            int rand3 = (int)random(3, gridSize-4);
            ag[i].setHypoX(rand2);
            ag[i].setHypoY(rand3);
          }
        }
      }

      for (int i = 0; i<popSize; i++) {
        if (ag[i].getStatus() == true) {


          xpos = ag[i].getHypoX();
          ypos = ag[i].getHypoY();
        }
      }




      int final_frequency = 0;
      int local_frequency = 0;


      if (index == 20) {

        for (int i = 0; i<popSize; i++) {

          int rIndex;
          if (i < popSize-1)
            rIndex = i+1;
          else
            rIndex = 0;
          if (ag[i].getHypoX() == ag[rIndex].getHypoX()) {
            if (ag[i].getHypoY() == ag[rIndex].getHypoY()) {
              local_frequency++;
            }
          } else {


            local_frequency = 0;
          }
          if (local_frequency > final_frequency)
          {
            final_frequency = local_frequency;


            collectRow.add(ag[i].getHypoX());
            collectCol.add(ag[i].getHypoY());


            posx = collectRow.get(collectRow.size()-1);
            posy = collectCol.get(collectCol.size()-1);
            
            
          }
        }
      }
    }
 
  }