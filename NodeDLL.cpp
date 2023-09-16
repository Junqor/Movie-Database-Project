#include "NodeDLL.h"

NodeDLL::NodeDLL() {
	name = "";
	next = nullptr;
	prev = nullptr;
	Movies = new CLL;
}

NodeDLL::NodeDLL(string d){
	name = d;
	next = nullptr;
	prev = nullptr;
	Movies = new CLL;
}