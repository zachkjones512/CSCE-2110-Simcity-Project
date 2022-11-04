#include "array2D.h"

Node*** CreateArray(int arrayX, int arrayY){
    Node*** array = new Node**[arrayX]; //Initialize 2D array
    
    for(int i = 0; i < arrayX; i++){  //Give that bad boy some depth
        array[i] = new Node*[arrayY];
        for(int j = 0; j < arrayY; j++){
            array[i][j] = new Node();
        }
    }

    return array;
}

void DestroyArray(Node*** array, int arrayX, int arrayY){
    for(int i = arrayX - 1; i >= 0; i--){  //Give that bad boy some depth
        for(int j = arrayY - 1; j >= 0; j--){
            delete array[i][j];
        }
        delete array[i];
    }
}

void PrintArray(Node*** array, int arrayX, int arrayY){
    for(int i = 0; i < arrayY; i++){        //Prints array
        for(int j = 0; j < arrayX; j++){
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

void PrintArray(Node*** array, int smallX, int smallY, int bigX, int bigY){
    for(int i = smallY; i < bigY; i++){ 
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