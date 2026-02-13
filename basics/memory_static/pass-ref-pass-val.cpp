#include<iostream>

void valSwap(std::string x, std::string y);
void refSwap(std::string &x, std::string &y);

int main(){
    std::string x= "Kool-Aid";
    std::string y= "Water";
    std::string temp;
    // note the address that show up here \/ when you run the code for some visual aid
    std::cout << &x << " |||| " << "LOCAL X: " << x << '\n';
    std::cout << &y << " |||| " << "LOCAL Y: " << y << '\n';
    // normally when calling a function we use | pass by VALUE |
    // we send a copy of the parameters rather than the parameter itself
    valSwap(x,y);

    std::cout << &x << " |||| " << "LOCAL X: " << x << '\n';
    std::cout << &y << " |||| " << "LOCAL Y: " << y << '\n';
    // when using & before a variable in the function we pass a memory address instead
    // or you can call it passing the REFERENCE to the value so | pass by REFERENCE |
    refSwap(x,y);

    std::cout << &x << " |||| " << "LOCAL X: " << x << '\n';
    std::cout << &y << " |||| " << "LOCAL Y: " << y << '\n';

    //a local swap
    temp= x;
    x= y;
    y= temp;

    std::cout << &x << " |||| " << "LOCAL X: " << x << '\n';
    std::cout << &y << " |||| " << "LOCAL Y: " << y << '\n';
    //use pass by REFERENCE as often as possible unless you have a reason to pass by VALUE

    return 0;
}
void valSwap(std::string x, std::string y){
    std::string temp;
    temp= x;
    x= y;
    y= temp;
    std::cout << &x << " |||| " << "VALUE X: " << x << '\n';
    std::cout << &y << " |||| " << "VALUE Y: " << y << '\n';
}
void refSwap(std::string &x, std::string &y){
    std::string temp;
    temp= x;
    x= y;
    y= temp;
    std::cout << &x << " |||| " << "REFERENCE X: " << x << '\n';
    std::cout << &y << " |||| " << "REFERENCE Y: " << y << '\n';
}