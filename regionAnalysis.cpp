#include "regionAnalysis.h"

void OutputPollution(Node*** array, int smallX, int smallY, int bigX, int bigY){
    for(int i = smallY; i < bigY; i++){        //Prints array
        for(int j = smallX; j < bigX; j++){
            Node* node = array[j][i];
            if(node->GetPollution() > 0){
                std::cout << node->GetPollution();
            }else{
                std::cout << node->GetType();
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int PollutionTotal(Node*** array, int smallX, int smallY, int bigX, int bigY){  //Returns total pollution from desired region
    int pollutionTotal = 0;
    for(int i = smallY; i < bigY; i++){        
        for(int j = smallX; j < bigX; j++){
            Node* node = array[j][i];
            pollutionTotal += node->GetPollution();
        }
    }
    return pollutionTotal;
}
void OutputRegion(Node*** array, int smallX, int smallY, int bigX, int bigY){
    for(int i = smallY; i < bigY; i++){        //Prints array
        for(int j = smallX; j < bigX; j++){
            Node* node = array[j][i];
            if(node->GetPop() > 0){
                std::cout << node->GetPop();
            }else{
                std::cout << node->GetType();
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int PopulationTotal(Node*** array, int smallX, int smallY, int bigX, int bigY){ //Returns total population from desired region
    int populationTotal = 0;
    for(int i = smallY; i < bigY; i++){        
        for(int j = smallX; j < bigX; j++){
            Node* node = array[j][i];
            populationTotal += node->GetPop();
        }
    }
    return populationTotal;
}
bool BoundsValid(int arrayX, int arrayY, int smallX, int smallY, int bigX, int bigY){
    if(smallX < 0 || smallY < 0 || bigX > arrayX || bigY > arrayY){
        return false;
    }else{
        return true;
    }
}