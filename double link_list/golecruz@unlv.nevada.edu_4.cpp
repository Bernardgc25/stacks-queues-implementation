//Bernard J. Gole Cruz, CS 202-2002, Assignment 6, problem 4
//This program implement double link-list with exception handling and sorting
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//global variable
//tracks id number starts from 100
int CAR_ID = 100;
//tracks list contents
int list_counter = 0;

//class record info definition
class RecordInfo{


private:
    //structure node for car
    struct Car{
        int id;            //value for id
        string make;       //value for make
        int price;         //value for price
        int year;          //value for year
        Car *next;         //pointer to next node
        Car *prev;         //pointer to previous node
           };
      Car *head;  //list head pointer
      Car *tail;  //list tail pointer

public:
    //constructor
     RecordInfo();
    //destructor
     ~RecordInfo();

    //link list operations
    void insertnode(int, string, int, int);     //insert node
    void deletenode(int, string, int, int);     //delete node
    void displayListforward();                  //display list
    void sortedListforward();                   //sort list newest
    void sortedListbackward();                  //sort list oldest


};
            /////function prototype/////
//////////////////////////////////////////////////////

        //class member function definitions//
//////////////////////////////////////////////////////

//constructor
RecordInfo::RecordInfo(){
     //set head to null
     head = NULL;
     tail = NULL;
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

    Car *newnode;
    //create new node
    newnode = new Car;

    Car *follownode;      //pointer to traverse list
    Car *trailnode;       //pointer to node before newnode


    //assign values to a node
    newnode->id = CAR_ID;
    newnode->make = MAKE;
    newnode->price = PRICE;
    newnode->year = YEAR;

    //insert node in an non-empty list
  if(position == 1 || head == NULL){
    //insert node in an empty list
    if(head == NULL && position == 1){
        newnode->prev = newnode->next = NULL;
        head = newnode;

        //update id starts from 100
         CAR_ID++;
        //update list content
         list_counter++;
        return;

    }
        //travers list and connects nodes
        head->prev = newnode;
        newnode->prev = NULL;
        newnode->next = head;
        head = newnode;

        //update id starts from 100
         CAR_ID++;
        //update list content
         list_counter++;
        return;

  }
    //insert at any position
    trailnode = head;
    for(int i=0; i<position-2; i++){
        trailnode = trailnode->next;
        }
    //traverse list and connect nodes
    newnode->next = trailnode->next;
    newnode->prev = trailnode;
    trailnode->next = newnode;

    //insert at last position
    if (newnode->next != NULL){
        follownode = newnode->next;
        follownode->prev = newnode;
        }


        //update id starts from 100
         CAR_ID++;
        //update list content
         list_counter++;
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


//display list in forward
void RecordInfo::displayListforward(){
    //scan the list

    Car *nodePtr;
    //set nodePtr to head
    nodePtr = head;

    cout << "CAR MANAGEMENT" << endl;
    cout << "Car List:" << endl;

    //traverse the list and display the elements

    while(nodePtr != NULL){

        cout << left << setw(6) << nodePtr->id << left << setw(12) << nodePtr->make <<
        left << setw(12) << nodePtr->price << left << setw(10) << nodePtr->year << endl;

        nodePtr = nodePtr->next;
    }
     cout << "----------" << endl;
     cout << endl;
};


//display list in sorted newest added
void RecordInfo::sortedListforward()
{
  cout <<"*****SORTED BY NEWEST ADDED*****" <<endl;

    //variables
    Car *ptr;
    Car *temp;
    temp = new Car;

    //less than 1 element in the list, no sort required.
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;

    //continue swapping while condition is true
    int swapped = 1;
    while (swapped) {
        swapped = 0;

        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->id < ptr->next->id) {

                // Swapping, need another pass.
                swapped = 1;

                //swapped by id
                temp->id = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = temp->id;

                //swapped by make
                temp->make = ptr->make;
                ptr->make = ptr->next->make;
                ptr->next->make = temp->make;

                //swapped by price
                temp->price = ptr->price;
                ptr->price = ptr->next->price;
                ptr->next->price = temp->price;

                //swapped by id year
                temp->year= ptr->year;
                ptr->year = ptr->next->year;
                ptr->next->year = temp->year;
            }
                //traverse the list
                ptr = ptr->next;
        }
    }
}



//display list in sorted oldest added
void RecordInfo::sortedListbackward(){
   cout <<"*****SORTED BY OLDEST ADDED*****" <<endl;
  Car *newnode;
    Car *ptr;
    Car *temp;
    temp = new Car;


    //less than 1 element in the list, no sort required.
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;

    //continue swapping while condition is true
    int swapped = 1;
    while (swapped) {
        swapped = 0;

        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->id > ptr->next->id) {
                // Swapping

                swapped = 1;
                //swapped by id
                temp->id = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = temp->id;

                //swapped by make
                temp->make = ptr->make;
                ptr->make = ptr->next->make;
                ptr->next->make = temp->make;

                //swapped by price
                temp->price = ptr->price;
                ptr->price = ptr->next->price;
                ptr->next->price = temp->price;

                //swapped by id year
                temp->year= ptr->year;
                ptr->year = ptr->next->year;
                ptr->next->year = temp->year;
            }
                //traverse the list
                ptr = ptr->next;
        }
    }
}



//////////////////////////////////////////////////////
    //non-class member function definitions//
//////////////////////////////////////////////////////

//menu
void menu(){

    //display choice
    cout << "Options:" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Remove Car" << endl;
    cout << "3. print list (sort by newest added first)" << endl;
    cout << "4. print list (sort by oldest added first)"  << endl;
    cout << "5. Exit" << endl;

};

//prompt user
void prompt(RecordInfo &obj, int &choice)
{
    //variables
    int Id, Year, Price;
    string Make;


    //keep prompting if user choose number outside the menu
    try{
    menu();
       cout << "Enter: ";
       if(!(cin >>choice) ){
            cin.clear();
            cin.ignore(100,'\n');
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
        //display contents
        //clear screen in each iteration
        system("CLS");
        obj.displayListforward();
        break;

    case 2:
        //remove node from list
        obj.deletenode(Id, Make, Year, Price);
        //clear screen in each iteration
        system("CLS");
        //display contents
        obj.displayListforward();
        break;

    case 3:
        //sort in newest
        obj.sortedListforward();
         //display contents
        obj.displayListforward();
        //clear screen in each iteration
        system("CLS");
        obj.displayListforward();

        break;
    case 4:
        //sort in oldest
        obj.sortedListbackward();
        //display contents
        obj.displayListforward();
        //clear screen in each iteration
        system("CLS");
        obj.displayListforward();

        break;
    case 5:
        //exit menu
            exit(0);

        default:
            //keep prompting until a correct choice is made
            //clear screen in each iteration
            system("CLS");
            obj.displayListforward();
            cout << "try again, choose between 1 - 5" << endl;

        }
};





int main(){
    //variables
    int select;

    //RecordInfo object
    RecordInfo list;
    //flag
    bool success = false;

    cout << "CAR MANAGEMENT" << endl;
    cout << "Car List:" << endl;
    cout << "----------";
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
