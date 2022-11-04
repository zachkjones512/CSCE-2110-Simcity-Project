#include <iostream>
#include "node.h"

Node*** CreateArray(int arrayX, int arrayY);
void DestroyArray(Node*** array, int arrayX, int arrayY);
void PrintArray(Node*** array, int arrayX, int arrayY);
void PrintArray(Node*** array, int smallX, int smallY, int bigX, int bigY);