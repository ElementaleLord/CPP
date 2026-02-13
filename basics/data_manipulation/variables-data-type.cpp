#include <iostream>
int main(){
    // integer (whole numbers)
    int x; // declaration
    x = 5; // assignment
    int y = 5; // as another way to declare and assign
    int days = 7.5, age = 19;//yet another way to declare and assign

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << x+y << std::endl;
    std::cout << days << std::endl;
    // double (a number including decimal)
    double price = 10.99, gpa = 2.5, temperature = 25.1;

    std::cout << price << std::endl;
    // char (single character)
    char grade = 'A', initial='B';

    std::cout<< initial << std::endl;
    // bool (true or false)
    bool student = true,power = false,for_sale= true;

    std::cout << student << std::endl;
    // string (sequence of text) technnicaly an object
    std::string name = "Bro",day= "Friday",food= "pizza",address= "123 Fake Street";

    std::cout << "Hello " << name << " you are " << age << " years old!" << std::endl;

    return 0;
}