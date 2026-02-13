#include <iostream>

int main(){
    // fill() = fills a range of elements with a specified values
    // syntax = fill(begin, end, value)

    std::string foods[10]= {"pizza","pizza","pizza","pizza","pizza","pizza","pizza","pizza","pizza","pizza"};
    for(std::string food: foods){
        std::cout << food << ' ';
    }
    std::cout << std::endl;
    // the above method is a work but impractical method to initialize each element manually
    // one the more practical ways is using fill take the below example for instance
    const int SIZE= 99;
    std::string animals[SIZE];

    fill(animals, animals + (SIZE/3), "dog");
    fill(animals + (SIZE/3), animals + (SIZE/3*2), "cat");
    fill(animals + (SIZE/3*2), animals + SIZE, "mouse");
    
    for(std::string animal: animals){
        std::cout << animal << ' ';
    }
    std::cout << std::endl;

    return 0;
}