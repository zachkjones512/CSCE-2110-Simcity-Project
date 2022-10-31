#include "regionAnalysis.h"

void OutputPollution(Node*** array, int smallX, int smallY, int bigX, int bigY){
    for(int i = smallY; i < bigY; i++){        //Prints array
        for(int j = smallX; j < bigX; j++){
            Node* node = array[j][i];
            if(node->GetPollution() > 0){
                std::cout << node->GetPop();
            }else{
                std::cout << node->GetType();
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int PollutionTotal(Node*** array, int smallX, int smallY, int bigX, int bigY){}
void OutputRegion(Node*** array, int smallX, int smallY, int bigX, int bigY){}
int PopulationTotal(Node*** array, int smallX, int smallY, int bigX, int bigY){}
bool BoundsValid(Node*** array, int smallX, int smallY, int bigX, int bigY){}