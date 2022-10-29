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
    //Accessors
        char GetType();
        int GetPop();
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