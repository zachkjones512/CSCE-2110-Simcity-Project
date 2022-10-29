#include "reszone.h"
#include "checkAdjacent.h"

void resUpdate(Node*** array1, Node*** array2, int arrayx, int arrayy){

    for(int i=0; i<arrayy; ++i){


        for(int j=0; j<arrayx; ++j){


            int popnum = checkAdjacent(array2, i, j, arrayx, arrayy); //assigns adjacent cell total population to a num

            switch(array2[j][i]->GetPop()){

            case 0:
            if (popnum >=1){
                array2[j][i]->SetPop(1);
            }
            break;

            case 1:
            if (popnum >=2){
                array2[j][i]->SetPop(2);
            }
            break;

            case 2:
            if (popnum >=8){
                array2[j][i]->SetPop(3);
            }
            break;

            case 3:
            if (popnum >=18){
                array2[j][i]->SetPop(4);
            }
            break;

            case 4:
            if (popnum >=32){
                array2[j][i]->SetPop(5);
            }
            break;            

            default:
            break;
        }
    }



}
}