#pragma once



#include "ofMain.h"
#include <vector>
#include "Chromosome.hpp"
#include "Grid.hpp"
#include "Cell.hpp"
#include "SDS.hpp"
#include "Agent.hpp"
#include "ofxGui.h"
#include "Colours.hpp"



class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
    //---------------------------------------
    
    vector<Chromosome> getParents(int parent1, int parent2);
    
  
    void diffusionPhase();
    int getIndex(int index);
    void generate();
    void mirrored();
    void rules();
    vector<Chromosome> cr;

    //-------------------------------------- GUI

       int newIndex;
	ofxPanel gui;
    //Grid gr;
    ofParameter<ofColor> col;
    //ofParameter<ofColor> color2;
    //ofParameter<ofColor> color2;
    ofParameter<bool> generation;
    ofParameter<bool> complementary;
    ofParameter<bool> tertiary;
    
    
    Colours cols;
    //vector<Agent> ag;
    vector<Grid> gr;
    int size;
    int trueindex;
    bool populate;
    int parent1;
    int parent2;
    int i;
    int it;
    int best;
    int var;

    bool init = true;
    
    vector< vector<int> > temp;
      vector< vector<int> > temp2;
    vector< vector<int> > next;
      vector< vector<int> > temp4;
    vector< vector<int> > rightGrid;
    vector< vector<int> > newTemp3;
    void testPhase(vector< vector<int> > temp);
    vector<int> tempIndex;

    int popSize;
    bool** checkSymmetry(bool symmetry[false][false]);
    int ssSize;
    bool symmetry[false][false];
    void generated();
    int getIndex(int x, int y, vector< vector<int> > newTemp3);
    bool symmetrical;
    int segmentSize;


    int boundaryY;
    int boundaryX;
    int currentHypoX;
    int currentHypoY;
    int c;
    
    
    int count;
    int numCols = 24;
    int numRows = 24;
    int cellWidth = 20;
    int cellHeight = 20;
    int cellSize = 20;
    int height = 480;
    int width = 480;

};
