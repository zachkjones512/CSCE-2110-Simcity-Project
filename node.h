#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
    //Constructors
        Node();
        Node(char nodeType);
    //Mutators
        void SetType(char nodeType);
        void SetPop(int pop);
        void SetWork(int worker);
        void SetPollution(int pollution);
    //Accessors
        char GetType();
        int GetPop();
        int GetWork();
        int GetPollution();
    //Destructors
        ~Node();
    private:
        char nodeType;
        int population;
        int pollution;
        int workers;
        int goods;
};
#endif