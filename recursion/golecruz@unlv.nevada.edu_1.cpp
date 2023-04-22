//Bernard J. Gole Cruz, CS 202-2002, Assignment 6, problem 1
//This program implement recursion and exception handling
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//function prototype
double power(int x, int y);
void prompt(int x, int y);

int main()
{
int num1, num2;
bool success = false;

//keep prompting if user enters non double data
while(!success){
    try{
        prompt(num1, num2);
        success = true;
        }
    catch(...){
        cout << "NON-INTEGER, TRY AGAIN!" << endl;
        }

}

    return 0;

}

//function definition
//prompt user for number and exponent, with exception
void prompt(int x, int y){

    try{
        //prompt for a number
        cout << "Enter a number: ";
        //throw x if not an integer
        if( !(cin>>x) ){
            cin.clear();
            cin.ignore(100,'\n');
            throw x;
                }
        }
    catch(int x){
        throw;
        }

    try{
        //prompt for exponent
        cout << "Enter an exponent: ";
        //throw y if not an integer
        if( !(cin>>y) ){
            cin.clear();
            cin.ignore(100,'\n');
            throw y;
                }
        }
     catch(int y){
        throw;
        }

        cout <<"Result: " << power(x,y);

}

//power function using recursion
double power(int x, int y){
    //base case
    if(y == 0){
        return 1;
        }
    //base case
    else if (y == 1){
        return x;
        }
    //general case
    else if (y > 1){
        return x * power(x,y-1);
        }
    //general case
    else
        return 1 / power(x, -y);
}
