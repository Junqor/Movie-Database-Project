#pragma once
#include "NodeCLL.h"

//CLL for list of movies in a category
//Need a CLL for each node in the DLL
class CLL {
public:
	CLL();
	~CLL();
	void AddMovie(string);
	NodeCLL* SearchMovie(string);
	int GetIndex(string);
	void RemoveMovie(string);
	void RemoveMovies(Date*);
	void Display();

private:
	NodeCLL* head; //Movie names
};

