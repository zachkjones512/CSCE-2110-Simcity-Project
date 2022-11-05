#include <iostream>
#include <fstream>
#include <string>
#include "array2D.h"
#include "reszone.h"
#include "indzone.h"
#include "commzone.h"
#include "regionAnalysis.h"

int main(){
    //INITIALIZATION
    std::string input, regionFile;
    char inputChar;
    int maxSteps = 0, refreshRate = 0;
    int arrayX = 0, arrayY = 0;
    int workers = 0, goods = 0, pollution = 0;

    std::cout << "Please give the config file name (config)" << std::endl;
    std::getline(std::cin, input);

    std::ifstream file;  //Open file
    file.open(input);
    std::getline(file, input, ':');
    std::getline(file, regionFile); //Store region file
    std::getline(file, input, ':');
    std::getline(file, input);
    maxSteps = std::stoi(input);    //Store max number of steps
    std::getline(file, input, ':');
    std::getline(file, input);
    refreshRate = std::stoi(input); //Store refresh rate
    file.close();   //Close config file

    //Some really hacky string manipulation to get it to work on Linux
    input = regionFile;
    regionFile.clear();
    regionFile = input.at(0);
    for(int i = 1; input.at(i) != '.' && i < 100; i++){
        regionFile = regionFile + input.at(i);
    }
    regionFile = regionFile + ".csv";
    file.open(regionFile);

    std::getline(file, input, '\n');
    
    arrayX = (input.size() / 2);


    while(!file.eof()){    //Get Y dimension of the region
        arrayY++;
        std::getline(file, input);
    }
    std::cout << "success 2" << std::endl;
    file.clear();
    file.seekg(0);  //Restart at beginning of file
    
    Node*** array1 = CreateArray(arrayX, arrayY);
    Node*** array2 = CreateArray(arrayX, arrayY);
    
    for(int i = 0; i < arrayY; i++){        //Fills array1 and array2 with region info
        for(int j = 0; j < arrayX; j++){
            inputChar = file.get();
            array1[j][i]->SetType(inputChar);
            array2[j][i]->SetType(inputChar);
            file.get();
        }
        file.get();
    }        
    std::cout << "INITIAL REGION:" << std::endl;
    PrintArray(array1, arrayX, arrayY); //Output initial region
    std::cout << std::endl << std::endl;

    //END INITIALIZATION

    bool hasChanged = true;
    //SIMULATION LOOP
    //TODO: REIMPLEMENT HASCHANGED IN MAIN
    for(int i = 0; i < maxSteps; i++){
        hasChanged = false;
        //DoUpdate(array1, array2, arrayX, arrayY, hasChanged);
        commUpdate(array1, array2, arrayX, arrayY, workers, goods, hasChanged);
        indUpdate(array1, array2, arrayX, arrayY, workers, goods, pollution, hasChanged);
        resUpdate(array1, array2, arrayX, arrayY, workers, hasChanged); //Always is last updated


        //Switch the arrays
        Node*** temp = array2;
        array2 = array1;
        array1 = temp;

        //Refresh rate check
        if(i % refreshRate == 0){
            std::cout << "REGION AT TIME STEP " << i + 1 << std::endl;
            std::cout << "DEBUG: workers: " << workers << ", goods: " << goods << std::endl; 
            PrintArray(array1, arrayX, arrayY);
            std::cout << std::endl << std::endl;
        }
    }

    //POST-SIMULATION TOOLS
    
    input = " ";
    while(input.compare("6") != 0){
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Output the final region state" << std::endl;
        std::cout << "2. Output the total population for residential, industrial, and commercial zones" << std::endl;
        std::cout << "3. Output the final pollution state" << std::endl;
        std::cout << "4. Output the total pollution" << std::endl;
        std::cout << "5. Get the total population and pollution for a sub-region (UNFINISHED)" << std::endl;
        std::cout << "6. Quit program" << std::endl;
        std::getline(std::cin, input);
        switch(input.at(0)){
            case '1':
                std::cout << std::endl << "FINAL REGION STATE:" << std::endl;
                PrintArray(array1, arrayX, arrayY);
                std::cout << std::endl;
            break;
            case '2':
                std::cout << std::endl << "TOTAL POPULATION:" << PopulationTotal(array1, 0, 0, arrayX, arrayY) << std::endl << std::endl;
            break;
            case '3':
                std::cout << std::endl << "FINAL POLLUTION STATE:" << std::endl;
                OutputPollution(array1, 0, 0, arrayX, arrayY);
                std::cout << std::endl;
            break;
            case '4':
                std::cout << std::endl << "TOTAL POLLUTION:" << PollutionTotal(array1, 0, 0, arrayX, arrayY) << std::endl << std::endl;
            break;
            case '5':
                RegionExplorer(array1, arrayX, arrayY);
            break;
            case '6':
            break;
            default:
                std::cout << "\nPlease enter a valid menu option.\n" << std::endl;
            break;
        }
    }
    

    //CLEANUP
    DestroyArray(array1, arrayX, arrayY);   //Frees memory allocated to arrays
    DestroyArray(array2, arrayX, arrayY);

    return 0;
}