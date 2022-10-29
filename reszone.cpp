#include "reszone.h"
#include "checkAdjacent.h"

void resUpdate(Node*** array1, Node*** array2, int arrayx, int arrayy){

    for(int i=0; i<arrayy; ++i){


        for(int j=0; j<arrayx; ++j){


            int popnum = checkAdjacent(array2, i, j, arrayx, arrayy); //assigns adjacent cell total population to a num

            switch(array2[j][i]->GetPop())

            case 0:
            break;

            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;            

            default:
            break;
        }
    }



}