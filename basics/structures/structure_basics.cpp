#include<iostream>
// structure definition
struct student{
    std::string name;
    double gpa;
    bool enrolled= true;//you can set default values for members of a structure
};

int main(){
    /*
    struct = A structure that group related variables under one name
             structs can contain many different data types (string, integer, double, boolean, character, etc.)
             variables in a structure are known as "members"
             members can be access with (.) "Class Member Access Operator"
    */
   //struct declaration
   student student1;
   student1.name= "Spongebob";
   student1.gpa= 3.2;
   student1.enrolled= true;

   student student2;
   student2.name= "Patrick";
   student2.gpa= 2.1;
   student2.enrolled= true;

   student student3;
   student3.name= "Squidward";
   student3.gpa= 1.5;
   student3.enrolled= false;

   std::cout << student1.name << '\n';
   std::cout << student1.gpa << '\n';
   std::cout << student1.enrolled << '\n';

   std::cout << student2.name << '\n';
   std::cout << student2.gpa << '\n';
   std::cout << student2.enrolled << '\n';

   std::cout << student3.name << '\n';
   std::cout << student3.gpa << '\n';
   std::cout << student3.enrolled << '\n';

    return 0;
}