#include<iostream>



int main(){
    // memory address = a location in memory where data is stored
    // a memory address can be accessed with & (memory-of operator)

    // a variable is a container for some data
    // this data exists on the computer in a place called a memory address
    std::string name= "Bro";
    int age= 21;
    bool student= true;

    //to figure out the name of the memory address we can do the following
    std::cout << &name << '\n';
    std::cout << &age << '\n';
    std::cout << &student << '\n';


    return 0;
}