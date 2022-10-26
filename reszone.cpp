#include "reszone.h"

void resUpdate(Node*** array1, Node*** array2, int arrayx, int arrayy){

    for(int i=0; i<arrayy; ++i){


        for(int j=0; j<arrayx; ++j){

            if(array2[j][i]->GetType() == 'R'){
                std::cout << j << ", " << i << "\n";
            }


        }
    }



}