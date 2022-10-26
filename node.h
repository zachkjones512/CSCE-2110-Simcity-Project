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
    //Accessors
        char GetType();
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