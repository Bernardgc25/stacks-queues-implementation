//Bernard J. Gole Cruz, CS 202-2002, Assignment 6, problem 3
//This program implement link-list with exception handling
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//global variable
//id number starts from 100
int I=100;

class RecordInfo{


private:
    //structure for car list
    struct Car{
        int id;            //value for id
        string make;       //value for make
        int price;         //value for price
        int year;          //value for year
        Car *next;         //pointer to next node
           };
      Car *head;  //list head pointer

public:
    //constructor
     RecordInfo();
    //destructor
     ~RecordInfo();

    //link list operations
    void insertnode(int, string, int, int);
    void deletenode(int, string, int, int);
    void displayList();
};


//function prototype and definitions

//constructor
RecordInfo::RecordInfo(){
     //set head to null
     head = NULL;
}

//destructor
RecordInfo::~RecordInfo(){
    //to traverse the list
    Car *nPtr;
    //point to next node
    Car *nextnode;

    //set nPtr as head
    nPtr = head;

    //scan the list and delete each node
    while (nPtr != NULL){
        nextnode = nPtr->next;
        //delete current node
        delete nPtr;
        //set nPtr to nextnode
        nPtr = nextnode;
    }
}
//add node at any position
void RecordInfo::insertnode(int ID, string MAKE, int YEAR, int PRICE){

    Car *newnode;
    //create new node
    newnode = new Car;

    int position;

    //prompt user for position,keep prompting until correct input
    cout << "Enter position: ";
    while(!(cin >>position) ){
            cout << "Enter position: ";
            cin >> position;
            cin.clear();
            cin.ignore(100,'\n');
                    }
    //prompt user for make,keep prompting until correct input
    cout << "Enter make: ";
       while(!(cin >> MAKE) ){
            cout << "Enter make: ";
            cin >> MAKE;
            cin.clear();
            cin.ignore(100,'\n');
                    }
    //prompt user for price,keep prompting until correct input
    cout << "Enter price: ";
       while(!(cin >> PRICE) ){
            cout << "Enter price: ";
            cin >> PRICE;
            cin.clear();
            cin.ignore(100,'\n');
                    }
    //prompt user for year,keep prompting until correct input
    cout << "Enter year: ";
        while(!(cin >> YEAR) ){
            cout << "Enter year: ";
            cin >> YEAR;
            cin.clear();
            cin.ignore(100,'\n');
                    }
    //clear screen in each iteration
    system("CLS");

    //assign values to a node
    newnode->id = I;
    newnode->make = MAKE;
    newnode->price = PRICE;
    newnode->year = YEAR;

    //set new node to null
    newnode->next = NULL;

    //insert new node in first position if list is empty
    if (position == 1){
        newnode->next = head;
        head = newnode;
        //update id starts from 100
        I++;
        return;
    }

    //to traverse the list
    Car *nPtr;
    //make new node
    nPtr = head;
    //insert node at any position
    for(int i=0; i<position-2; i++){
        nPtr = nPtr->next;
    }
    newnode->next = nPtr->next;
    nPtr->next = newnode;
    //update id starts from 100
    I++;
}

//remove node from list
void RecordInfo::deletenode(int ID, string MAKE, int YEAR, int PRICE ){

    //to traverse the list
    Car *nPtr;
    //point to previous node
    Car *prev;

    //delete node using id
    cout <<"Enter id of car to be remove:"; cin >> ID;

    //clear screen in each iteration
    system("CLS");
    nPtr->id = ID;

    //do nothing if list is empty
    if(!head)
        return;

    //check if if the first node match the item to be deleted
    if(head->id == ID){
        nPtr = head->next;
        delete head;
        head = nPtr;
        }
    else{
        //set nodeptr as head
        nPtr = head;

        //skip nodes that do not match
        while(nPtr != NULL && nPtr->id != ID){
            prev = nPtr;
            nPtr = nPtr->next;
            }
        //link previous node to next node
        if(nPtr){
            //delete node that has the matching item
            prev->next = nPtr->next;
            delete nPtr;
            }
        }
}


//display list
void RecordInfo::displayList(){
    //scan the list
    Car *nodePtr;
    //set nodePtr to head
    nodePtr = head;

    cout << endl;
    cout << endl;
    cout << "CAR MANAGEMENT" << endl;
    cout << "Car List:" << endl;

    //traverse the list and display the elements
    while(nodePtr){

        cout << left << setw(6) << nodePtr->id << left << setw(12) << nodePtr->make <<
        left << setw(12) << nodePtr->price << left << setw(10) << nodePtr->year << endl;

        nodePtr = nodePtr->next;
    }
     cout << "----------" << endl;
};

//menu
void menu(){

    //display choice

    cout << "Options:" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Remove Car" << endl;
    cout << "5. Exit" << endl;

};

//prompt user
void prompt(RecordInfo &obj, int &choice)
{
    int Id, Year, Price;
    string Make;


    //keep prompting if user choose number outside the menu
    try{
    cout << endl;
    cout << endl;

    menu();
       cout << "Enter: ";
       if(!(cin >>choice) ){
            cin.clear();
            cin.ignore(100,'\n');


            //clear screen in each iteration
            system("CLS");
            throw choice;

                    }
        }
       catch(int choice){
            throw;
            }

    int value;
    //choices in menu
    switch (choice){
    case 1:
        //insert node in list
        obj.insertnode(Id, Make, Year, Price);
        //clear screen in each iteration
        system("CLS");
         //display list contents
        obj.displayList();


        break;

    case 2:
        //remove node from list
        obj.deletenode(Id, Make, Year, Price);
        //display list contents
        obj.displayList();
        //clear screen in each iteration
        system("CLS");


        break;

    case 5:
        //exit menu
            exit(0);

        default:

         //keep prompting until a correct choice is made
         //clear screen in each iteration
         system("CLS");



        }
};


int main(){
    int select;
    //RecordInfo object, create car list
    RecordInfo list;
    bool success = false;


    cout << endl;
    cout << endl;
    cout << "CAR MANAGEMENT" << endl;
    cout << "Car List:" << endl;
    cout << "----------";// <<;// endl;
    cout << endl;

    //exception handling
    while(true){
        try{
            prompt(list, select);

            success = true;
            }
        catch(...){
            }
        }


    return 0;
}
