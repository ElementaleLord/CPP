#include <iostream>
int main ()
{
    // break = break out of the loop
    // continue = skip the current iteration
    std::cout << "Continue:\n";
    for (int i= 1; i <=20; i++){
        if (i==13){
            continue;
        }
        std::cout << i;
    }
    std::cout << "\nBreak:\n";
    for (int i= 1; i <=20; i++){
        if (i==13){
            break;
        }
        std::cout << i;
    }
    return 0;
}