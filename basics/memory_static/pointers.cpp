#include<iostream>
int main(){
    /*
    pointers = variable that stores a memory address of another variable
    WHY!?!?! = sometimes it's easier to work with an address
    */
    /*
    & address-of operator
    * dereference operator
    */
    std::string Name= "Patrick";
    /*
    to create a pointer it SHOULD be of
    the SAME data type as the variable its pointing to
    syntax ===> type * variable;
    common naming convention is to add p before the name
    of the variable were pointing to and use that as the pointers name
    */
    std::string * pName= &Name;/*
    ^^^^ = pointer of type: string and name: pName
    it's = pointing to variable of type: string and name: Name
    */
    std::cout << pName << '\n';//displays the address that is stored in the pointer
    /*
    the pointer contains a memory address as its value
    to access the value at the address we use the dereference operator (*)
    */
    std::cout << *pName << '\n';//displays the value that is stored at the address the pointer points to
    //few more examples:
    // integers
    int Age= 21;
    int * pAge= &Age;//same type as variable
    std::cout << pAge << '\n';
    std::cout << *pAge << '\n';
    // arrays
    std::string FreePizzas[5]= {"Pizza1","Pizza2","Pizza3","Pizza4","Pizza5"};
    // its easier to use the address of the array rather then the array itself
    std::string * pFreePizzas= FreePizzas;
    // do note as array are already addresses there no need for the address-of operator (&)
    std::cout << FreePizzas << '\n';    // displays the address of array
    std::cout << *FreePizzas << '\n';   // displays the first element of the array
    std::cout << pFreePizzas << '\n';   // displays the address of the array
    std::cout << *pFreePizzas << '\n';  // displays the first elements of the array

    return 0;
}