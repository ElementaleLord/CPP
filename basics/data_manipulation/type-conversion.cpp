#include <iostream>

int main (){

    // type conversion = conversion of a value of one data type to another
    //                  Implicit = automatic
    //                  Explicit = Precede value with the new data type (int)
    //example of implicit conversion 1
    int x = 3.14; //this is a truck-a-ted value
    std::cout << x << " ";
    //example of explicit conversion 1
    double y = (int) 3.14;
    std::cout << y << " ";
    //example of implicit conversion 2
    char z= 100;
    std::cout << z << " ";
    //example of explicit conversion 2
    std::cout << (char) 100 << " ";

    //little exercise
    int correct= 8, questions= 10;
    //double score= correct/questions * 100; 
    // ^^^ doesn't work bc the division gets truck-a-ted by the int type
    double score= correct/ (double) questions * 100;

    std::cout << score << "%" << " ";

    std::cout << std::endl;
    return 0;
}