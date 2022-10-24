#include <iostream>
#include <fstream>
#include <string>
//#include "array2D.h"

int main(){
    //INITIALIZATION
    std::string input, regionFile;
    char inputChar;
    int maxSteps = 0, refreshRate = 0;
    int arrayX = 0, arrayY = 0;

    std::cout << "Please give the config file name (config)" << std::endl;
    std::getline(std::cin, input);

    std::ifstream file(input);  //Open file
    std::getline(file, regionFile); //Store region file
    std::getline(file, input);
    maxSteps = std::stoi(input);    //Store max number of steps
    std::getline(file, input);
    refreshRate = std::stoi(input); //Store refresh rate
    file.close();   //Close config file
    
    file.open(regionFile);
    inputChar = file.get();
    while(inputChar != '\n'){   //Get X dimension of array
        if(inputChar != ','){
            arrayX++;
        }
        inputChar = file.get();
    }

    while(!file.eof()){    //Get Y dimension of the array
        arrayY++;
        std::getline(file, input);
    }

    file.clear();
    file.seekg(0);  //Restart at beginning of file

    



    //Node*** array1, array2;
    //END INITIALIZATION

    //SIMULATION LOOP

    //POST-SIMULATION TOOLS

    //CLEANUP

    return 0;
}