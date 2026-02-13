#include <iostream>

int main (){

    // arithmetic operators = return the result of a specific
    //                        arithmetic operation (+ - * /)
    double students= 20;
    //addition
    students = students + 1;
    students+= 1; //short-hand notation of the above
    students++;//different short-hand to adding 1
    //subtraction
    students = students - 1;
    students-= 1; //short-hand notation of the above
    students--;//different short-hand to subbing 1
    //multiplication
    students = students * 2;
    students*= 2; //short-hand notation of the above
    //division
    students = students / 2;
    students/= 2; //short-hand notation of the above
    //modulo
    int student=20;
    student = student % 6;
    student%= 6; //short-hand notation of the above
    

    std::cout << students << std::endl;


    return 0;
}