#include <iostream>
#include <fstream>
#include <string>
#include "array2D.h"
#include "reszone.h"

int main(){
    //INITIALIZATION
    std::string input, regionFile;
    char inputChar;
    int maxSteps = 0, refreshRate = 0;
    int arrayX = 0, arrayY = 0;

    std::cout << "Please give the config file name (config)" << std::endl;
    std::getline(std::cin, input);

    std::ifstream file(input);  //Open file
    std::getline(file, regionFile, ':');
    std::getline(file, regionFile); //Store region file
    std::getline(file, input, ':');
    std::getline(file, input);
    maxSteps = std::stoi(input);    //Store max number of steps
    std::getline(file, input, ':');
    std::getline(file, input);
    refreshRate = std::stoi(input); //Store refresh rate
    file.close();   //Close config file
    
    file.open(regionFile);
    inputChar = file.get();
    while(inputChar != '\n'){   //Get X dimension of the region
        if(inputChar != ','){
            arrayX++;
        }
        inputChar = file.get();
    }
    
    while(!file.eof()){    //Get Y dimension of the region
        arrayY++;
        std::getline(file, input);
    }

    file.clear();
    file.seekg(0);  //Restart at beginning of file

    Node*** array1 = createArray(arrayX, arrayY);
    Node*** array2 = createArray(arrayX, arrayY);

    for(int i = 0; i < arrayY; i++){        //Fills array1 and array2 with region info
        for(int j = 0; j < arrayX; j++){
            inputChar = file.get();
            array1[j][i]->SetType(inputChar);
            array2[j][i]->SetType(inputChar);
            file.get();
        }
        file.get();
    }

    for(int i = 0; i < arrayY; i++){        //Prints initial region
        for(int j = 0; j < arrayX; j++){
            inputChar = file.get();
            std::cout << array1[j][i]->GetType() << " ";
        }
        std::cout << std::endl;
    }    

    resUpdate(array1, array2, arrayX, arrayY);
    //TODO: ADD ARRAY VALUES

    //END INITIALIZATION

    //SIMULATION LOOP

    //POST-SIMULATION TOOLS

    //CLEANUP

    return 0;
}