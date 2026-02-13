#include <iostream>

int main()
{
    // for loop = a loop that will execute a block of code a specified amount of time
    for (int i=1; i<=10;i++){
        std::cout << i << '\n';
    }
    std::cout << "Happy New Year!\n";
    for (int i=0; i<=10;i+=2){
        std::cout << i << '\n';
    }
    std::cout << "Happy New Year!\n";
    for (int i=10; i>=0;i--){
        std::cout << i << '\n';
    }
    std::cout << "Happy New Year!\n";
    return 0;
}