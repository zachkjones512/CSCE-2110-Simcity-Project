#include "commzone.h"


void commUpdate(Node*** array1, Node*** array2, int arrayX, int arrayY, int &workers, int &goods){

    for(int i=0; i<arrayy; ++i){


        for(int j=0; j<arrayx; ++j){

            if(array1[j][i]->GetType() == 'C'){
                int popnum = checkAdjacent(array1, i, j, arrayx, arrayy); //assigns adjacent cell total population to a num

                    switch(array1[j][i]->GetPop()){ //switch case to check for update conditions

                    case 0: //if pop is 0 and there's an adjacent cell with a pop of 1, increase current cell population
                    if (popnum >=1 && goods >= 1 && workers >= 1){
                        array2[j][i]->SetPop(1);
                        --goods;
                        --workers;
                    }
                    break;

                    case 1:
                    if (popnum >=2 && goods >= 1 && workers >= 1){
                        array2[j][i]->SetPop(2);
                        --goods;
                        --workers;
                    }
                    break; 

    
                    default: //do nothing if population is more than or equal to 2.
                    break;
                }
                    }
    }



}
}



    

