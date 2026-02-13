#include <iostream>

int main ()
{
    // do while loop = do some block of code first,
    //                 THEN repeat again if condition is true

    int number;

    while (number < 0)
    {
       std::cout << "Enter a positive #: ";
       std::cin >> number;
    }
    
    std::cout << "The # is: " << number;
    
    do
    {
       std::cout << "Enter a 2nd positive #: ";
       std::cin >> number;
    }while (number < 0);
    
    std::cout << "The 2nd # is: " << number;

    return 0;
}