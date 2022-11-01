#include "commzone.h"
#include "checkAdjacent.h"

void commUpdate(Node*** array1, Node*** array2, int arrayX, int arrayY, int &workers, int &goods){

    for(int i=0; i<arrayY; ++i){


        for(int j=0; j<arrayX; ++j){

            if(array1[j][i]->GetType() == 'C'){
                int popnum = checkAdjacent(array1, i, j, arrayX, arrayY); //assigns adjacent cell total population to a num

                    switch(array1[j][i]->GetPop()){ //switch case to check for update conditions

                    case 0: //if pop is 0 and there's an adjacent cell with a pop of 1, increase current cell population
                    if (popnum >=1 && goods >= 1 && workers >= 1){
                        array2[j][i]->SetPop(1);
                        --goods;
                        --workers;
                        array2[j][i]->SetWork(array2[j][i]->GetWork()+1);
                    }
                     else{
                        array2[j][i]->SetPop(array1[j][i]->GetPop());
                        }
                    break;

                    case 1:
                    if (popnum >=2 && goods >= 1 && workers >= 1){
                        array2[j][i]->SetPop(2);
                        --goods;
                        --workers;
                        array2[j][i]->SetWork(array2[j][i]->GetWork()+1);
                    }
                      else{
                        array2[j][i]->SetPop(array1[j][i]->GetPop());
                        }
                    break; 

    
                    default:
                        array2[i][j]->SetPop(array1[i][j]->GetPop());
                         //do nothing if population is more than or equal to 2.
                    break;
                }
                    }
    }



}
}



    

