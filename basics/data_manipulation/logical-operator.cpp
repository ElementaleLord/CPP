#include <iostream>

int main ()
{
    // && = check if two conditions are true
    // || = check if atleast one of the condition is true
    // ! == reverses the logical state of its operand

    int temp;
    bool sunny=true;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    if (temp >0 && temp< 30){
        std::cout << "The temperature is good!" << std::endl;
    }else{
        std::cout << "The temperature is bad!" << std::endl;
    }

    if (!sunny){
        std::cout << "It is cloudy outside!" << std::endl;
    }else{
        std::cout << "It is sunny outside!" << std::endl;
    }
    return 0;
}