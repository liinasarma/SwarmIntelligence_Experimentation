//
//  Chromosome.cpp
//  NaturalComputing CWK
//
//  Created by Lina  Sarma on 24/12/16.
//
//


//It must be noted that a variety of methods which implement the SDS algorithm within this program have been
//taken from an example provided in the Natural Computing labs, especially Agent class whilst the more detailed
//methdos of SDS such as testPhase and diffusion have been adapted to this problem
//the application named SymmetrySerial_NC is the one which contains many references



#include "ofApp.h"
#include <vector>
#include "Chromosome.hpp"
#include "Grid.hpp"
#include "Cell.hpp"
#include "SDS.hpp"
#include "Agent.hpp"
#include "cassert"
#include "Colours.hpp"

ofColor color3 = ofColor(176,102,96);
ofColor color4 = ofColor(219,173,114);
ofColor color2 = ofColor(155,175,142);
ofColor color1 = ofColor(106,125,142);
ofColor color5 = ofColor(106,125,142);

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    popSize = 200;
    segmentSize = 2;
    size = 30;
    
    
    for(int i = 0; i < 30; i++)
    {
        
        vector<int> temp; // create an array, don't work directly on buff yet.
        for(int j = 0; j < 30; j++)
            temp.push_back(4);
        rightGrid.push_back(temp); // Store the array in the buffer
        
    }
    

    
    
    cr.push_back(Chromosome());
    
    
    
    gr.push_back(Grid());
    gr.push_back(Grid());
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    
    
    
    
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    

    ofBackground(255);
    
    
    ofFill();

    
    
    gr[0].drawGrid(cr.at(best).genes, color1, color2, color3, color4, 0,100);
    
    
    cr.at(0).testPhase(rightGrid);
    
    
    
    
    
    
    int x = cr.at(0).posx;
    int y = cr.at(0).posy;
    
    
    
    
    int cellValue;
    
    
    
    
    int rowCurr = cr.at(0).posx;
    int colCurr = cr.at(0).posy;
    
    
    
    
    int boundaryRow = rowCurr+4;
    int boundaryCol = colCurr+4;
    
    
    
    
    
    
    
    if(rowCurr != 0){
        
        for(int row = rowCurr;row<boundaryRow; row++ ){
            
            
            for(int col = colCurr; col<boundaryCol; col++){
                
                
                int k = cr.at(0).genes.at(row).at(col);
                
                rightGrid.at(row).at(col) = k;
                
                
                
                
            }
            
        }
        
    }
    
    

    

    
//    for (int x = 1; x < rightGrid.size() - 1; x++) {
//        for (int y = 1; y < rightGrid.size() - 1; y++) {
//            
//            rightGrid.at(x).at(y) <-- 2;
//            
//            
//            cout<<rightGrid[x][y];
//            
//            
//            
    
            //
            //
            //            // Add up all the states in a 3x3 surrounding grid
            //
            //            /*
            //             //Moore Neighborhood
            //
            //
            //             for (int i = -1; i <= 1; i++) {
            //             for (int j = -1; j <= 1; j++) {
            //             neighbors += rightGrid[x+i][y+j];
            //             }
            //             }
            //             */
            //
            //            //Von Neumann Neighborhood
            //            int neighbors = 1;
            //            neighbors += rightGrid[x-1][y];
            //            neighbors += rightGrid[x+1][y];
            //            neighbors += rightGrid[x][y-1];
            //            neighbors += rightGrid[x][y+1];
            //
            //            //
            //            //            if (rules ==3) {
            //
            //            if ((rightGrid[x][y] == 0) && (neighbors ==3 || neighbors==1)) {
            //                rightGrid[x][y] = 1;
            //            } else if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
            //                rightGrid[x][y] = 2;
            //            } else if ((rightGrid[x][y] == 3 || rightGrid[x][y]==2) && (neighbors ==1 || neighbors ==3)) {
            //                rightGrid[x][y] = 3;
            //            } else if ((rightGrid[x][y] == 1 || rightGrid[x][y]==2) && (neighbors ==2 || neighbors ==3)) {
            //                rightGrid[x][y] = 4;
            //            }
//        }
//    }
//    
    
    rules();
    
    gr[1].drawGrid(rightGrid, color1, color2, color3, color4, 600,100);
    
    
    
    
    
    
}

void ofApp::rules(){
    int rules = 2;
    
    for (int x = 1; x < rightGrid.size() - 1; x++) {
        for (int y = 1; y < rightGrid.size() - 1; y++) {
            
            
            
            
            
            
            // Add up all the states in a 3x3 surrounding grid
            
            /*
             //Moore Neighborhood
             
             
             for (int i = -1; i <= 1; i++) {
             for (int j = -1; j <= 1; j++) {
             neighbors += rightGrid[x+i][y+j];
             }
             }
             */
            
            //Von Neumann Neighborhood
            int neighbors = 1;
//            neighbors += rightGrid.at(x-1).at(y);
//            neighbors += rightGrid.at(x+1).at(y);
//            neighbors += rightGrid.at(x).at(y-1);
//            neighbors += rightGrid.at(x).at(y+1);
            
            
            if (rules ==3) {
                
                if ((rightGrid[x][y] == 0) && (neighbors ==3 || neighbors==1)) {
                    rightGrid[x][y] = 1;
                } else if ((rightGrid[x][y] == 0) && (neighbors ==2)) {
                    rightGrid[x][y] = 2;
                } else if ((rightGrid[x][y] == 3 || rightGrid[x][y]==2) && (neighbors ==1 || neighbors ==3)) {
                    rightGrid[x][y] = 3;
                } else if ((rightGrid[x][y] == 1 || rightGrid[x][y]==2) && (neighbors ==2 || neighbors ==3)) {
                    rightGrid[x][y] = 4;
                }
                
                
                
            }
            else if(rules==2) {
                
                
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
            
            
            else if (rules==1) {
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
                
                
                if ((rightGrid[x][y] == 0) && (neighbors ==1)){
                    
                    rightGrid[x][y] = 3;   }
                else if((rightGrid[x][y] == 1) && (neighbors ==2 || neighbors ==3)){
                    rightGrid[x][y] = 4;
                }
                else if((rightGrid[x][y] == 2) && (neighbors ==2)){
                    rightGrid[x][y] = 2;   }
                else if((rightGrid[x][y] == 4 || rightGrid[x][y]==0) && (neighbors==4||neighbors ==2 || neighbors ==3)){
                    
                    rightGrid[x][y] = 3;
                }
                
                
            }
            
            
        }
        
        for(int i = 0; i < 30; i++)
        {
            
            vector<int> temp4; // create an array, don't work directly on buff yet.
            for(int j = 0; j < 30; j++)
                temp4.push_back(4);
            temp2.push_back(temp4); // Store the array in the buffer
            
        }
        
        temp2.clear();
        temp2 = rightGrid;
        rightGrid = next;
        next = temp2;
        
    }
}






//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
