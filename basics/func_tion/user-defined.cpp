#include <iostream>

void happy_Birth_name(std::string);
void happy_Birth_age(int age);
void happyBirthday(){
    std::cout << "Happy Birthday to you!\n";
    std::cout << "Happy Birthday to you!\n";
    std::cout << "Happy Birthday dear you!\n";
    std::cout << "Happy Birthday to you!\n\n";
}

int main ()
{
    //function = a block of reusable code
    std::string name="Patrick Farah";
    int age=19;
    happyBirthday();
    happy_Birth_name(name);//this is a function written with a prototype
    happy_Birth_age(age);

    return 0;
}
void happy_Birth_name(std::string name){
    std::cout << "Happy Birthday to " << name <<"!\n";
    std::cout << "Happy Birthday to " << name <<"!\n";
    std::cout << "Happy Birthday dear " << name <<"!\n";
    std::cout << "Happy Birthday to " << name <<"!\n\n";
}
void happy_Birth_age(int age){
    std::cout << "Happy Birthday you are " << age <<" years old!\n";
    std::cout << "Happy Birthday you are " << age <<" years old!\n";
    std::cout << "Happy Birthday dear!\n";
    std::cout << "Happy Birthday you are " << age <<" years old!\n\n";
}