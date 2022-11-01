#ifndef INDZONE_H
#define INDZONE_H

#include <iostream>
#include "node.h"

// for more info, visit indzone.cpp

void pollute(Node*** array2, int j, int i, int x, int y, int &pollution, int locPop);
void indUpdate(Node*** array1, Node*** array2, int arrayX, int arrayY, int &workers, int &goods);



#endif