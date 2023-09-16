#include <iostream>
#include <stdlib.h>
#include "NodeDLL.h"
#include "NodeCLL.h"
#include "DLL.h"
#include "CLL.h"
using namespace std;

//Function to convert strings to uppercase for easier string comparisons
void ToUpper(string &a) {
    for (int i = 0; i < size(a); i++) {
        a[i] = toupper(a[i]);
    }
}

int main()
{
    DLL* myDLL = new DLL();

    //These categories and movies are added by default for easier testing
    myDLL->AddCat("CHILDREN"); 
    myDLL->SearchCat("CHILDREN")->Movies->AddMovie("BARBIE");
    myDLL->SearchCat("CHILDREN")->Movies->SearchMovie("BARBIE")->SetDate(15, 2, 2022); // form: dd/mm/yyyy
    myDLL->AddCat("ACTION");
    myDLL->SearchCat("ACTION")->Movies->AddMovie("ROCKY");
    myDLL->SearchCat("ACTION")->Movies->SearchMovie("ROCKY")->SetDate(22, 3, 2021);
    myDLL->AddCat("COMEDY");
    myDLL->SearchCat("COMEDY")->Movies->AddMovie("TUXEDO");
    myDLL->SearchCat("COMEDY")->Movies->SearchMovie("TUXEDO")->SetDate(1, 11, 2022);
    system("CLS");

    int key = 0; //User input key for cases
    string name = ""; //Holds the user input category/movie name for the various cases
    bool flag = true; //Flag to exit loop

    while (flag) {
        cout << "Enter one of the following numbers or type anything else to quit: " << endl;
        cout << "1) Add a new category" << endl;
        cout << "2) Add a new movie" << endl;
        cout << "3) Search for a category" << endl;
        cout << "4) Search for a movie" << endl;
        cout << "5) Get Index of a movie" << endl;
        cout << "6) Remove a category" << endl;
        cout << "7) Delete all movies before a date" << endl;
        cout << "8) Print all movies" << endl;

        cin >> key;
        system("CLS");

        switch (key) {
        case 1:
            cout << "Enter category name to add: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This is needed to clear input stream
            getline(cin, name);                                  //so getline works properly
            ToUpper(name);
            myDLL->AddCat(name);
            break;

        case 2:
        {
            cout << "Enter the category name to add movie in: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            ToUpper(name);
            NodeDLL* tempCat = myDLL->SearchCat(name);
            if (tempCat) {
                cout << "Enter movie name to add: " << endl;
                getline(cin, name);
                ToUpper(name);
                if (myDLL->SearchMov(name)) {
                    cout << "This movie already exists! \n" << endl;
                    break;
                }
                tempCat->Movies->AddMovie(name);

                //Entering Date
                cout << "Enter a date for this movie: " << endl;
                int d = 0, m = 0, y = 0;
                cout << "Day: ";
                cin >> d;
                cout <<"Month: ";
                cin >> m;
                cout << "Year: ";
                cin >> y;
                tempCat->Movies->SearchMovie(name)->SetDate(d, m, y);
                cout << endl;
            }
            else {
                cout << "That category does not exist! " << endl << endl;
            }
            break;
        }

        case 3:
            cout << "Enter category name to search for: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            ToUpper(name);
            if (myDLL->SearchCat(name))
                cout << name << " category found!" << endl << endl;
            else
                cout << name << " category not found!" << endl << endl;
            break;

        case 4:
            cout << "Enter movie name to search for: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            ToUpper(name);
            if (myDLL->SearchMov(name))
                cout << name << " movie found!" << endl << endl;
            else
                cout << name << " movie not found!" << endl << endl;
            break;

        case 5:
        {
            cout << "Enter movie name to get it's index: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            ToUpper(name);
            NodeDLL* tempCat = myDLL->SearchMov(name);
            if (tempCat) { //Check if movie exists
                int index = tempCat->Movies->GetIndex(name);
                cout << "Found in " << tempCat->name << " at index: " << index << endl << endl;
            }
            else {
                cout << name << " movie not found!" << endl << endl;
            }
            break;
        }

        case 6:
            cout << "Enter category name to delete: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            ToUpper(name);
            myDLL->RemoveCat(name);
            break;

        case 7:
        {
            cout << "Enter from the date that you would like to delete: " << endl;
            int d = 0, m = 0, y = 0;
            cout << "Day: ";
            cin >> d;
            cout << endl << "Month: ";
            cin >> m;
            cout << endl << "Year: ";
            cin >> y;
            Date* tempDate = new Date(d, m, y);
            myDLL->DeleteMovies(tempDate);
            delete tempDate;
            break;
        }

        case 8:
            myDLL->DisplayAll();
            break;

        default:
            flag = false; //Exits while loop for any other input
            break;
        }
    }

    delete myDLL;
    
    return 0;
}