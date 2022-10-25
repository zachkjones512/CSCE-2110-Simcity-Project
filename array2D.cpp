#include "array2D.h"

Node*** createArray(int arrayX, int arrayY){
    Node*** array = new Node**[arrayX]; //Initialize 2D array
    
    for(int i = 0; i < arrayX; i++){  //Give that bad boy some depth
        array[i] = new Node*[arrayY];
        for(int j = 0; j < arrayY; j++){
            array[i][j] = new Node();
        }
    }

    return array;
}