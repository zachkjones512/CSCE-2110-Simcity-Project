#include "reszone.h"
#include "checkAdjacent.h"

void resUpdate(Node*** array1, Node*** array2, int arrayx, int arrayy, int &workers){

    for(int i=0; i<arrayy; ++i){


        for(int j=0; j<arrayx; ++j){

            if(array1[j][i]->GetType() == 'R'){            
                int popnum = checkAdjacent(array1, i, j, arrayx, arrayy); //assigns adjacent cell total population to a num

                switch(array1[j][i]->GetPop()){ //switch case to check for update conditions

                case 0: //if pop is 0 and there's an adjacent cell with a pop of 1, increase current cell population
                if (popnum >=1){
                    array2[j][i]->SetPop(1);
                    ++workers;
                }
                    else{
                        array2[i][j]->SetPop(array1[i][j]);
                        }
               
                break;

                case 1:
                if (popnum >=2){
                    array2[j][i]->SetPop(2);
                    ++workers;
                }
                    else{
                        array2[i][j]->SetPop(array1[i][j]);
                        }
                break;

                case 2:
                if (popnum >=8){
                    array2[j][i]->SetPop(3);
                    ++workers;
                }
                    else{
                        array2[i][j]->SetPop(array1[i][j]);
                        }
                
                break;

                case 3:
                if (popnum >=18){
                    array2[j][i]->SetPop(4);
                    ++workers;
                }
                    else{
                        array2[i][j]->SetPop(array1[i][j]);
                        }
                
                break;

                case 4:
                if (popnum >=32){
                    array2[j][i]->SetPop(5);
                    ++workers;
                }
                    else{
                        array2[i][j]->SetPop(array1[i][j]);
                        }
                
                break;            

                default: //do nothing if population is over 5.
                 array2[i][j]->SetPop(array1[i][j]);
                break;
                }
            }
    }



}
}