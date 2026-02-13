#include <iostream>
#include <cmath>

int main ()
{
    int x=5, y=8, p=-1;
    double a=1.5, b=5.2, c=3.6;

    // std::max(x, y) = gives the maximum of the two values
    std::cout << std::max(x, y) << std::endl;

    // std::min(x, y) = gives the minimum of the two values
    std::cout << std::min(x, y) << std::endl;

    // pow(x, y) = gives the power of the x to y
    std::cout << pow(x, y) << std::endl;

    // abs(x) = gives the absolute value of x
    std::cout << abs(p) << std::endl;
    
    // round(h) = gives the value of x rounded
    std::cout << round(a) << std::endl;
    
    // ceil(x) = gives the value of x rounded up
    std::cout << ceil(b) << std::endl;
    
    // floor(x) = gives the value of x rounded down
    std::cout << floor(c) << std::endl;

    // https://www.cplusplus.com/refence/cmath/
    // ^^^ link a reference site for libraries of cplusplus
    
    return 0;
}