#include "checkAdjacent.h"

bool isValidPos(int i, int j, int x, int y){

    if (i < 0 || j < 0 || i > y - 1 || j > x - 1) //checks to see if selected cell in for loop is included in the bounds of the array
        return false
    return true;



}

int checkAdjacent(Node*** arr, int i, int j, int x, int y){
    int sum = 0;

    if (isValidPos(i - 1, j - 1, x, y)){ //checks if cell is within the bounds of the array
        sum = sum + arr[j-1][i-1]->GetPop();//adds the population of the node to the sum
        if (arr[j-1][i-1]->GetPop() == 0 && arr[j-1][i-1]->GetType() == 'T' || arr[j-1][i-1]->GetType() == '#' || arr[j-1][i-1]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i - 1, j, x, y)){
        sum = sum + arr[j][i-1]->population;
        if (arr[j][i-1]->GetPop() == 0 && arr[j][i-1]->GetType() == 'T' || arr[j][i-1]->GetType() == '#' || arr[j][i-1]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i - 1, j + 1, x, y)){
        sum = sum + arr[j+1][i-1]->population;
        if (arr[j+1][i-1]->GetPop() == 0 && arr[j+1][i-1]->GetType() == 'T' || arr[j+1][i-1]->GetType() == '#' || arr[j+1][i-1]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i, j - 1, x, y)){
        sum = sum + arr[j-1][i]->population;
        if (arr[j-1][i]->GetPop() == 0 && arr[j-1][i]->GetType() == 'T' || arr[j-1][i]->GetType() == '#' || arr[j-1][i]->GetType() == 'P' ){
            ++sum;
        }    
    }
    if (isValidPos(i, j + 1, x, y)){
        sum = sum + arr[j+1][i]->population;
        if (arr[j+1][i]->GetPop() == 0 && arr[j+1][i]->GetType() == 'T' || arr[j+1][i]->GetType() == '#' || arr[j+1][i]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i + 1, j - 1, x, y)){
        sum = sum + arr[j-1][i+1]->population;
        if (arr[j-1][i+1]->GetPop() == 0 && arr[j-1][i+1]->GetType() == 'T' || arr[j-1][i+1]->GetType() == '#' || arr[j-1][i+1]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i + 1, j, x, y)){
        sum = sum + arr[j][i+1]->population;
        if (arr[j][i+1]->GetPop() == 0 && arr[j][i+1]->GetType() == 'T' || arr[j][i+1]->GetType() == '#' || arr[j][i+1]->GetType() == 'P' ){
            ++sum;
        }
    }
    if (isValidPos(i + 1, j + 1, x, y)){
        sum = sum + arr[j+1][i+1]->population;
        if (arr[j+1][i+1]->GetPop() == 0 && arr[j+1][i+1]->GetType() == 'T' || arr[j+1][i+1]->GetType() == '#' || arr[j+1][i+1]->GetType() == 'P' ){
            ++sum;
        }
    }

   return sum; //returns it to the original update function where it can be compared to the growth conditions

}