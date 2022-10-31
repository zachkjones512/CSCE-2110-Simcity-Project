#include <iostream>
#include "node.h"

void OutputPollution(Node*** array, int smallX, int smallY, int bigX, int bigY);
int PollutionTotal(Node*** array, int smallX, int smallY, int bigX, int bigY);
void OutputRegion(Node*** array, int smallX, int smallY, int bigX, int bigY);
int PopulationTotal(Node*** array, int smallX, int smallY, int bigX, int bigY);
bool BoundsValid(Node*** array, int smallX, int smallY, int bigX, int bigY);