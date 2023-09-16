#pragma once
#include <iomanip>
#include "NodeDLL.h"

//DLL for list of Categories
class DLL {
public:
    DLL();
    ~DLL();
    void AddCat(string);     //Add a Category
    void RemoveCat(string);  //Delete a category
    NodeDLL* SearchCat(string); //Search by category name
    NodeDLL* SearchMov(string); //Search by movie name
    void DisplayCategory();     //Print all categories
    void DeleteMovies(Date*);    //Delete movies before a date
    void DisplayAll();       //Print all movies from all categories
private:
    NodeDLL* head;
};

