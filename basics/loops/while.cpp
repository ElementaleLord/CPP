#include <iostream>

int main()
{
    std::string name;
    // while loop is like an if statement but one that can be repeated a potentially infinite amount of time
    while(name.empty()){
        std::cout << "enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name;
    //infinite loop
    /*
    while(true)
    std::cout << "Help! Im stuck in an infinite loop!!!!";
    //*/

    return 0;
}