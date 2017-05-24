int w = 10;

int[] cells;

 // We arbitrarily start with just the middle cell having a state of "1"
int generation = 0;

// An array to store the ruleset, for example {0,1,1,0,1,1,0,1}
int[] ruleset = {0, 1, 0, 1, 1, 0, 1, 0};

void setup() {

  size(1200, 800);
  //background(0);
  cells = new int[500];
  for (int i = 0; i < cells.length; i++) {
    cells[i] = 0;
  }
  cells[cells.length/2] = 1;

}

void draw() {

  for (int i = 0; i < cells.length; i++) {
    if (cells[i] == 1) {
      fill(255);
    } else {
      fill(0);
      noStroke();
      rect(i*w, generation*w, w, w);
    }
  }
  if (generation < height/w) {
    generate();
  }
}

// The process of creating the new generation
void generate() {
  // First we create an empty array for the new values
  int[] nextgen = cells;
  // For every spot, determine new state by examing current state, and neighbor states
  // Ignore edges that only have one neighor
  for (int i = 1; i < cells.length-1; i++) {
    int left   = cells[i-1];   // Left neighbor state
    int me     = cells[i];     // Current state
    int right  = cells[i+1];   // Right neighbor state
    nextgen[i] = rules(left, me, right); // Compute next generation state based on ruleset
  }
  // The current generation is the new generation
  cells = nextgen;
  generation++;
}


// Implementing the Wolfram rules
// Could be improved and made more concise, but here we can explicitly see what is going on for each case
int rules(int a, int b, int c) {
  if (a == 1 && b == 1 && c == 1) return ruleset[0];
  if (a == 1 && b == 1 && c == 0) return ruleset[1];
  if (a == 1 && b == 0 && c == 1) return ruleset[2];
  if (a == 1 && b == 0 && c == 0) return ruleset[3];
  if (a == 0 && b == 1 && c == 1) return ruleset[4];
  if (a == 0 && b == 1 && c == 0) return ruleset[5];
  if (a == 0 && b == 0 && c == 1) return ruleset[6];
  if (a == 0 && b == 0 && c == 0) return ruleset[7];
  return 0;
}