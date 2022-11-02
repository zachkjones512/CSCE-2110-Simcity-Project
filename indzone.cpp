/*
    Programmer: Daniel Kaderli
    Class: CSCE 2110.002
    Date: 10/31/2022
    Description: indzone.cpp contains pollution and industrial update functionality.
    Variables:
        array1: original array pre-update
        array2: resulting array post-update
        arrayX/x: max value of x-axis of region
        arrayY/y: max value of y-axis of region
        j/i: current position in region (x/y respective)
        locPop: current cell population
        popNum: sum of population of adjacent cells

    Functions:
        void pollute(...): sets pollution for cell and spreads to adjacent cells
        void indUpdate(...): updates information for industrial cells 

*/

#include "indzone.h"
#include "checkAdjacent.h"


void pollute(Node*** array2, int j, int i, int x, int y, int &pollution, int locPop){
    array2[j][i]->SetPollution(locPop);
    
    if(locPop > 1){
        if (isValidPos(i - 1, j - 1, x, y)){ // checks if cell is within region (this repeats)
            array2[j-1][i-1]->SetPollution(locPop-1); // sets pollution to one less than cells pollution (this also repeats)
        }
        if (isValidPos(i - 1, j, x, y)){
            array2[j][i-1]->SetPollution(locPop-1);
        }
        if (isValidPos(i - 1, j + 1, x, y)){
            array2[j+1][i-1]->SetPollution(locPop-1);
        }
        if (isValidPos(i, j - 1, x, y)){
            array2[j-1][i]->SetPollution(locPop-1);
        }
        if (isValidPos(i, j + 1, x, y)){
            array2[j+1][i]->SetPollution(locPop-1);
        }
        if (isValidPos(i + 1, j - 1, x, y)){
           array2[j-1][i+1]->SetPollution(locPop-1);
        }
        if (isValidPos(i + 1, j, x, y)){
            array2[j][i+1]->SetPollution(locPop-1);
        }
        if (isValidPos(i + 1, j + 1, x, y)){
            array2[j+1][i+1]->SetPollution(locPop-1);
        }
    }
}

void indUpdate(Node*** array1, Node*** array2, int arrayX, int arrayY, int &workers, int &goods, int &pollution, bool &hasChanged){

    for(int i=0; i<arrayY; ++i){        // loops through array vertically
        for(int j=0; j<arrayX; ++j){    // loops through array horizontally
            if(array1[j][i]->GetType() == 'I'){
                
                int popNum = checkAdjacent(array1, i, j, arrayX, arrayY); //assigns adjacent cell total population to a num
                int locPop = array1[j][i]->GetPop();
                pollute(array2, j, i, arrayX, arrayY, pollution, locPop);
                goods = goods + locPop; // increases goods proportional to cell population
                switch(array1[j][i]->GetPop()){ //switch case to check for update conditions

                    case 0: // if pop is 0, check if there's 1 neighbor and 2 workers
                    if (popNum >=1 && workers >= 2){
                        // if there is. add one to the pop and hire the workers (this repeats)
                        array2[j][i]->SetPop(1);    
                        workers = workers - 2;
                        array2[j][i]->SetWork(array2[j][i]->GetWork()+2);
                        hasChanged = true;
                    }else{
                        // if not, population remains unchanged (this also repeats)
                        array2[j][i]->SetPop(0);
                    }
                    break;

                    case 1: // if pop is 1, check if there's 2 neighbors and 2 workers
                    if (popNum >= 2 && workers >= 2){
                        array2[j][i]->SetPop(2);
                        workers = workers - 2;
                        array2[j][i]->SetWork(array2[j][i]->GetWork()+2);
                        hasChanged = true;
                    }else{
                        array2[j][i]->SetPop(1);
                    }
                    break;

                    case 2: // if pop is 2, check if there's 8 neighbors and 2 workers
                    if (popNum >= 8 && workers >= 2){
                        array2[j][i]->SetPop(3);
                        workers = workers - 2;
                        array2[j][i]->SetWork(array2[j][i]->GetWork()+2);
                        hasChanged = true;
                    }else{
                        array2[j][i]->SetPop(2);
                    }

    
                    default: //do nothing if population is more than or equal to 3.
                    break;
                }
            }
        }
    }
}



    

