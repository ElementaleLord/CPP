#include <iostream>

enum Day {sunday= 0, monday= 1, tuesday= 2, 
          wednesday= 3, thursday= 4, friday= 5,
          saturday= 6};

enum Flavor {vanilla, chocolate, strawberry, mint};/*
Note that if you dont specifically assign a value to the
//elements of an enum then you implicitly assign the values 0 to names
//in the order of elements
in the enum Flavor 
vanilla is implicitly 0 
and chocolate is implicitly 1 
and strawberry is implicitly 2
and so forth
*/
enum Color {red, orange, yellow, green, blue, purple};

enum Planet {//the associated int value is the size of the planet in KM
             mercury= 4880, venus= 12104, earth= 12756,
             mars= 6794, jupiter= 142984, saturn= 108728,
             uranus= 51118, neptune= 49532, pluto= 2320};

int main(){
    /*
    enums = a user-defined data type that consists of
            paired names-integer constants.
            GREAT if you have a set of potential options
    */
    Day today= sunday;
    /*
    a switch can only take an integer or enum variable
    if you try to use strings you will get a type error

    you would only be able to use the values in the enum set
    any other declarations will be considered out of this scope
    (apart from you know the default stuff)
    */
    switch(today){
        case 0:
            std::cout << "It's Sunday!\n";
            break;
        case 1:
            std::cout << "It's Monday!\n";
            break;
        case 2:
            std::cout << "It's Tuesday!\n";
            break;
        case 3:
            std::cout << "It's Wednesday!\n";
            break;
        case 4:
            std::cout << "It's Thursday!\n";
            break;
        case 5:
            std::cout << "It's Friday!\n";
            break;
        case 6:
            std::cout << "It's Saturday!\n";
            break;
    }


    return 0;
}