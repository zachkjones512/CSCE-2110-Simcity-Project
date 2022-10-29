#include "node.h"

//Constructors
Node::Node(){
    //Defaults to road if no type
    this->nodeType = 'r';
    this->population = 0;
    this->pollution = 0;
    this->workers = 0;
    this->goods = 0;
}
Node::Node(char nodeType){
    this->nodeType = nodeType;
    this->population = 0;
    this->pollution = 0;
    this->workers = 0;
    this->goods = 0;
}
//Mutators
void Node::SetType(char nodeType){
    this->nodeType = nodeType;
}
void Node::SetPop(int pop){
    this->population = pop;
}
//Accessors
char Node::GetType(){
    return this->nodeType;
}
int Node::GetPop(){
    return this->population;
}
//Destructors
Node::~Node(){
    //TODO: ADD STUFF
}