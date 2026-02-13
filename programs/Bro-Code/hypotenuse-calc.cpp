#include <iostream>
#include <cmath>
/* personal attempt
int main()
{
    int a, b, c;
    std::cout << "Enter the length of side A: ";
    std::cin >> a;
    std::cout << "Enter the length of side B: ";
    std::cin >> b;
    c= sqrt( pow( a, 2) + pow( b, 2));
    std::cout << "Result :" << c << std::endl;

    return 0;
}
*/
int main()
{
    double a;
    double b;
    double c;

    std::cout << "Enter side A: ";
    std::cin >> a;
    std::cout << "Enter side B: ";
    std::cin >> b;

    a= pow( a, 2);
    b= pow( b, 2);
    c=sqrt(a+b);

    std::cout << "Side C:" << c << std::endl;

    return 0;
}