#include <iostream>

int main (){
    // sizeof() = determines the size in bytes of a:
    //            variables, data type, class, objects, etc.

    std::string name= "Bro Code Is Awesome";
    double gpa= 2.5;
    char grade= 'F';
    bool student= true;
    char grades[]= {'A','B','C','D','E','F'};
    std::string students[]= {"Spongebob","Patrick","Squidward"};

    std::cout << sizeof(int) << " Bytes" << std::endl;
    std::cout << sizeof(name) << " Bytes" << std::endl;
    std::cout << sizeof(gpa) << " Bytes" << std::endl;
    std::cout << sizeof(grade) << " Bytes" << std::endl;
    std::cout << sizeof(student) << " Bytes" << std::endl;
    std::cout << sizeof(grades) << " Bytes" << std::endl;
    std::cout << sizeof(grades)/sizeof(grades[0]) << " Elements" << std::endl;
    // ^^^ trick to figure out the number of element in an array
    std::cout << sizeof(students)/sizeof(std::string) << " Elements" << std::endl;
    // ^^^ alternate trick to figure out the number of elements in an array

    return 0;
}