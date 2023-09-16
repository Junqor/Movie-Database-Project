#include "DLL.h"

DLL::DLL() {
    head = nullptr;
}

DLL::~DLL() {
    while (head->next) {
        NodeDLL* temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
}

//Function to add a category to the list alphabetically
void DLL::AddCat(string a) {
    //First check if category name already exists
    if (SearchCat(a)) { 
        cout << "This category already exists! \n" << endl;
        return;
    }
    NodeDLL* A = new NodeDLL(a);
    if (head == nullptr) { //If list is empty
        head = A;
    }
    else if (head->name > a) { //Insert before head
        head->prev = A;
        A->next = head;
        head = A;
    }
    else {
        NodeDLL* temp = head;
        NodeDLL* current = head->next;
        while ((current != nullptr) && (current->name < a)) {    
                temp = temp->next;
                current = current->next;
        }
        if (current == nullptr) { //First condition fails, reaches end of list
            temp->next = A; //Insert at the end
            A->prev = temp;
        }
        else { //Second condition fails, current category name comes after alphabetically
            temp->next = A; //Insert between temp and current
            current->prev = A;
            A->next = current;
            A->prev = temp;
        }
    }
    cout << a << " category added! " << endl << endl;
}

//Function to remove a category, given the name as an input
void DLL::RemoveCat(string a) {
    NodeDLL* current = SearchCat(a); //Stores result of category search
    if (current == nullptr) { //Check if category doesn't exists
        cout << "That category does not exist! \n" << endl;
        return;
    }

    //Case 1 : Category is at the beginning (head)
    if (current == head) {
        //If theres only one node, then just delete head
        if (current->next == nullptr) {
            head = nullptr;
            delete current;
        }
        //If followed by another category then make that the new head
        else {
            NodeDLL* nxt = current->next;
            nxt->prev = nullptr;
            head = nxt;
            delete current;
        }
    }
    //Case 2 : Category is at the end
    else if (current->next == nullptr) {
        NodeDLL* previous = current->prev;
        previous->next = nullptr;
        delete current;
    }
    //Case 3 : Category is somewhere in the middle
    else {
        NodeDLL* previous = current->prev;
        NodeDLL* nxt = current->next;
        previous->next = nxt;
        nxt->prev = previous;
        delete current;
    }
    cout << "Category deleted! \n" << endl;
}

//Function to search if a category already exists or not
NodeDLL* DLL::SearchCat(string a) {
    //If head is null, then there are no categories
    if (head == nullptr) {
        return nullptr;
    }
    NodeDLL* temp = head;
    while (temp != nullptr) {
        //If it is found return the node
        if (temp->name == a) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

//Function to search for a movie without knowing category name
//  Returns pointer to the category that it was found in
NodeDLL* DLL::SearchMov(string a) {
    //Base case: head is null
    if (head == nullptr) {
        return nullptr;
    }
    NodeDLL* current = head;
    //Loop through each category node and search for movie
    while (current != nullptr) 
    {
        if (current->Movies->SearchMovie(a)) { //If it exists in current node
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//Function to display all the categories
void DLL::DisplayCategory() {
    //Base Case: There are no categories
    if (head == nullptr) {
        cout << "No Categories Exist" << endl;
        return;
    }
    cout << "Categories: " << endl;
    NodeDLL* temp = head;
    //Iterate through and print each category name
    while (temp != nullptr) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

//Function to delete all movies before a certain date
void DLL::DeleteMovies(Date* checkDate) {
    //Base case: head is null
    if (head == nullptr) {
        return;
    }
    NodeDLL* current = head;
    //Loop through each category node and delete movies that are before that date
    while (current != nullptr)
    {
        current->Movies->RemoveMovies(checkDate);
        current = current->next;
    }
    cout << "Movies deleted! " << endl << endl;
}

//Function to print every category and every movie in them
void DLL::DisplayAll() {
    if (head == nullptr) {
        cout << "No Categories Exist! " << endl << endl;
        return;
    }
    NodeDLL* current = head;
    //Loop through each category
    while (current) {
        cout << current->name << " Movies: " << endl;
        current->Movies->Display();
        current = current->next;
    }
}