#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)
int main()
{
    std::string name;
    int age;
    std::cout << "What's your age?: ";
    std::cin >> age;

    //using std::getline so that we can input strings with spaces
    //dealing with the left over '\n' by using std:ws in std::getline
    std::cout << "What's your full name?: ";
    std::getline(std::cin >> std::ws, name);


    std::cout << "Hello " << name << std::endl;
    std::cout<< "You are " << age << " years old";

    return  0;
}