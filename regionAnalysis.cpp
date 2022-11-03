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
    if(smallX < 0 || smallY < 0 || bigX >= arrayX || bigY >= arrayY || smallX > bigX || smallY > bigY){
        return false;
    }else{
        return true;
    }
}

void RegionExplorer(Node*** array, int arrayX, int arrayY){ //For examining a sub-region
    std::string input;
    int smallX = -1, smallY = -1, bigX = -1, bigY = -1;
    bool firstTry = true;

    while(!BoundsValid(arrayX, arrayY, smallX, smallY, bigX, bigY)){    //Get valid bounds from the user
        if(!firstTry){                                  //Lets the user know what the valid bounds are
            std::cout << "Bounds must be greater than or equal to 0.\nUpper Y-bound must be less than or equal to " << arrayY - 1<< ".\nUpper X-bound must be less than or equal to " << arrayX - 1<< "." << std::endl;
        }
        try{
            std::cout << "Please enter the smallest X-bound:" << std::endl;
            std::getline(std::cin, input);
            smallX = std::stoi(input);
            std::cout << "Please enter the largest X-bound:" << std::endl;
            std::getline(std::cin, input);
            bigX = std::stoi(input);
            std::cout << "Please enter the smallest Y-bound:" << std::endl;
            std::getline(std::cin, input);
            smallY = std::stoi(input);
            std::cout << "Please enter the largest Y-bound:" << std::endl;
            std::getline(std::cin, input);
            bigY = std::stoi(input);
            firstTry = false;
        }
        catch (std::invalid_argument){  //If the user puts in anything other than an integer, prompt for a valid input
            std::cout << "Please enter a valid integer value." << std::endl;
        }
    }

    std::cout << "SUB-REGION FROM ("<< smallX << "," << smallY << ") TO (" << bigX << "," << bigY << ") INCLUSIVE:" << std::endl;
    OutputRegion(array, smallX, smallY, bigX + 1, bigY + 1);
    std::cout << "TOTAL POPULATION: " << PopulationTotal(array, smallX, smallY, bigX + 1, bigY + 1) << ", TOTAL POLLUTION: " << PollutionTotal(array, smallX, smallY, bigX + 1, bigY + 1) << std::endl;
    std::cout << std::endl << std::endl;
}