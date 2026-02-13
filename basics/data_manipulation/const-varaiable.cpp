#include <iostream>

int main(){
    // the const keyword specifies that a variable's value is constant
    // tells the compiler to prevent anything from modifying it
    // (read only)
    const double PI=3.14159, LIGHT_SPEED= 299792458, WIDTH= 1360;
    //PI=420.69;//error due to not being a modifiable value
    double radius = 10;
    double circumference= 2 * PI * radius;

    std::cout << circumference << "cm" << std::endl;


    return 0;
}