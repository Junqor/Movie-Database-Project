#include "NodeCLL.h"

NodeCLL::NodeCLL() {
	name = "";
	next = nullptr;
	prev = nullptr;
}

NodeCLL::NodeCLL(string a) {
	name = a;
	next = nullptr;
	prev = nullptr;
}

//Function to set the date the movie was uploaded
void NodeCLL::SetDate(int d, int m, int y) {
	uploadDate.day = d;
	uploadDate.month = m;
	uploadDate.year = y;
}
