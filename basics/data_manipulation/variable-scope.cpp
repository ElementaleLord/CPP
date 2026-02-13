#include <iostream>

int myNum =3;
// ^ This is a global variable
// Recommended to not be usee as they pollute the local namespace

void printNum();

int main ()
{
    // Local variable = declared inside a function or block {}
    // Global variables = declared outside ALL functions
    // a function will use the local version of a variable first before thee global version
    int myNum= 1;
    // ^ This is a local variable

    printNum();

    return 0;
}
void printNum(){
    int myNum =2;
    //functions cant see the local variables of another function
    std::cout << myNum << '\n';
}