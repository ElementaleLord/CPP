#include <iostream>
int main()
{
    // ternary operator ?: = replacement to an if/else statement
    // condition ? expresion 1 : expresion2;

    int grade= 75;
    //if/else method
    if (grade >= 60)
    {
        std::cout << "You pass! ";
    }
    else{
        std::cout << "You fail! ";
    }
    //ternary method
    grade >= 60 ? std::cout << "You pass!" : std::cout << "You fail!";
    
    std::cout << std::endl;

    int number = 9;
    number % 2 == 1 ? std::cout << "ODD " : std::cout << "EVEN ";
    number % 2 ? std::cout << "ODD" : std::cout << "EVEN";
    
    std::cout << std::endl;

    bool hungry=true;

    hungry ? std::cout << "You are hungry " : std::cout << "You are full ";
    std::cout << (hungry ? "You are hungry" : "You are full");

    return 0;
}