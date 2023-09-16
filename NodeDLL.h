#pragma once
#include "CLL.h"

//Node for category
//Each node has a CLL for the list of movies
class NodeDLL {
public:
    NodeDLL();
    NodeDLL(string);
    ~NodeDLL() {}
    string name;
    NodeDLL* next;
    NodeDLL* prev;
    CLL* Movies;
};
