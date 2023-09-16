#pragma once
#include <string>
#include <iostream>
using namespace std;

//Date class to store date movie was added
class Date {
public:
    Date() { day = 0, month = 0, year = 0; };
    Date(int d, int m, int y) { day = d, month = m, year = y; };
    int day;
    int month;
    int year;
};

//Node class for movies
//Includes date class
class NodeCLL{
public:
    NodeCLL();
    NodeCLL(string);
    ~NodeCLL() {}
    string name;
    NodeCLL* next;
    NodeCLL* prev;
    Date uploadDate;
    void SetDate(int, int, int);
};
