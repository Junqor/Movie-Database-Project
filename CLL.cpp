#include "CLL.h"

CLL::CLL() {
	head = nullptr;
}

CLL::~CLL() {
    //Go through and delete each node until it circles back to the head
    NodeCLL* current = head->next;
    while (current != head) {
        NodeCLL* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

//Function to add a movie name to the category alphabetically
void CLL::AddMovie(string a) {
    if (SearchMovie(a)) {
        cout << "This movie already exists \n" << endl;
        return;
    }
	NodeCLL* A = new NodeCLL(a);
	if (head == nullptr) { //If list is empty
		head = A;
        head->next = head;
        head->prev = head;
	}
    else if (head->name > a) { //Insert before head
        head->prev->next = A; 
        A->prev = head->prev; //Make last node and new node point to eachother
        head->prev = A;
        A->next = head; //Make head and new node point to eachother
        head = A; //Make new node head
    }
    else {
        NodeCLL* temp = head;
        NodeCLL* current = head->next;
        while ((current != head) && (current->name < a)) {
            temp = temp->next;
            current = current->next;
        }
        if (current == head) { //First condition fails, circles back to head
            temp->next = A; //Insert at the end
            A->prev = temp;
            A->next = current;
            current->prev = A;
        }
        else { //Second condition fails, current movie name comes after alphabetically
            temp->next = A; //Insert between temp and current
            current->prev = A;
            A->next = current;
            A->prev = temp;
        }
    }
    cout << "Movie Added Successfully! \n" << endl;
}

//Function to search for a movie given the movie name
NodeCLL* CLL::SearchMovie(string a) { 
    //If head is null, then there are no categories
    if (head == nullptr) {
        return nullptr;
    }
    NodeCLL* temp = head;
    do 
    {
        //If it is found return the node
        if (temp->name == a) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head); //Search until temp loops back to the head

    //Else it was not found
    return nullptr;
}

//Function to get a movies index counted in clockwise order
int CLL::GetIndex(string a) {
    //Base Case: movie doesn't exist
    if (SearchMovie(a) == nullptr) {
        return -1;
    }
    NodeCLL* current = head;
    int index = 0;
    do
    {
        //If it is found return the index
        if (current->name == a) {
            return index;
        }
        index += 1;
        current = current->next;
    } while (current != head); //Search until current loops back to the head

    //Else it was not found
    return -1;
}

//Function to delete a specific movie
void CLL::RemoveMovie(string a) {
    NodeCLL* current = SearchMovie(a); //Stores result of movie search
    if (current == nullptr) { //Check if category doesn't exists
        return;
    }

    //Case 1 : Movie is at the beginning (head)
    if (current == head) {
        //If theres only one node, then just delete head
        if (current->next == current) {
            head = nullptr;
            delete current;
        }
        //If followed by another movie thats not itself then make that the new head
        else {
            NodeCLL* nxt = current->next;
            nxt->prev = current->prev;
            current->prev->next = nxt;
            head = nxt;
            delete current;
        }
        return;
    }
    //Case 2 : Movie is somewhere in the middle
    else {
        NodeCLL* previous = current->prev;
        NodeCLL* nxt = current->next;
        previous->next = nxt; 
        nxt->prev = previous; //Get the nodes after and before it to point to eachother
        delete current;
        return;
    }
}

//Function to delete all movies before a specific date
void CLL::RemoveMovies(Date* checkDate) {
    //Base Case: head is null
    if (head == nullptr) {
        return;
    }
    NodeCLL* current = head->next;
    NodeCLL* currentNxt = current->next;
    do
    {
        //First compare the years
        if (current->uploadDate.year < checkDate->year) 
        {
            RemoveMovie(current->name);
        }
        else if (current->uploadDate.year == checkDate->year) 
        { //If the years are equal then compare the month
            if (current->uploadDate.month < checkDate->month) 
            {
                RemoveMovie(current->name);
            }
            else if (current->uploadDate.month == checkDate->month) 
            { //If the years and months are equal, check the day
                if (current->uploadDate.day < checkDate->day) 
                {
                    RemoveMovie(current->name);
                }
            }
        }
        if (currentNxt) { //Check if currentNxt is not null;
            current = currentNxt;
            currentNxt = current->next;
        }
        else break;
    } while ((current != head) && (head != nullptr)); //Traverse until temp loops back to the head

    //Compare head after (same as in the loop but just for head)
    current = head;
    if (current->uploadDate.year < checkDate->year) {
        RemoveMovie(current->name);
    }
    else if (current->uploadDate.year == checkDate->year) {
        if (current->uploadDate.month < checkDate->month) {
            RemoveMovie(current->name);
        }
        else if (current->uploadDate.month == checkDate->month) { 
            if (current->uploadDate.day < checkDate->day) {
                RemoveMovie(current->name);
            }
        }
    }
}

//Function to display all movies in a category
void CLL::Display() {
    if (head == nullptr) {
        cout << "No movies" << endl << endl;
        return;
    }
	NodeCLL* temp = head;
    do
    {
        cout << temp->name  << ", Upload date: " << temp->uploadDate.month 
            << "/" << temp->uploadDate.day << "/" 
            << temp->uploadDate.year << endl;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}