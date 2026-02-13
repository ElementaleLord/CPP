#include<iostream>

class Student{
    public:
        std::string name;
        int age;
        double GPA;

    // constructor definiton / declaration / instantiation
    Student(std::string name, int age, double gpa){
        /*
        to remove ambiguity in the case of similar names we use
        the 'this' keyword
        syntax:
        this->attribute-name= value;
        */
        this->name= name;
        this->age= age;
        GPA= gpa;
    }
};
class Car{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

    Car(std::string make, std::string model, int year, std::string color){
        this->make= make;
        this->model= model;
        this->year= year;
        this->color= color;
    }         
};

int main(){
    /*
    constructors = Special method that is automatically called
                    when an object is instantiated
                   Useful for assigning values to attributes as arguments
    */
    /*
    Before when we were assigning values to attributes we would use like
    car1.color= "red";
    Well with a constructor we can do that automatically
    */
    // Heres an example:
    /*
    To assign some of the attribute right away we could use a constructor
    We do have a constructor that is automatically called behind the scenes
    But we can explicitly set one up.
    check the class for the constructor
    */
    /*
        then when I instantiate a student object i will add a set of ()
        after the object-name then pass in my arguments
    */
    Student student1("Patrick Farah", 20, 3);
    Student student2("Charbel Fares", 19, 2.6);
    Student student3("Charbel Outayek", 19, 3.1);
    Student student4("Jean Chamoun", 19, 2.8);
    Student student5("Omar Hammoud", 18, 2.7);
    Student student6("Billal Hammoud", 18, 2.9);

    std::cout << student1.name << '\n';
    std::cout << student1.age << '\n';
    std::cout << student1.GPA << '\n';

    std::cout << student2.name << '\n';
    std::cout << student2.age << '\n';
    std::cout << student2.GPA << '\n';

    std::cout << student3.name << '\n';
    std::cout << student3.age << '\n';
    std::cout << student3.GPA << '\n';

    std::cout << student4.name << '\n';
    std::cout << student4.age << '\n';
    std::cout << student4.GPA << '\n';

    std::cout << student5.name << '\n';
    std::cout << student5.age << '\n';
    std::cout << student5.GPA << '\n';

    std::cout << student6.name << '\n';
    std::cout << student6.age << '\n';
    std::cout << student6.GPA << '\n';

    Car car1("Cheevy", "Corvette", 2022, "blue");
    Car car2("Ford", "Mustang", 2023, "red");

    std::cout << car1.make << '\n';
    std::cout << car1.model << '\n';
    std::cout << car1.year << '\n';
    std::cout << car1.color << '\n';

    std::cout << car2.make << '\n';
    std::cout << car2.model << '\n';
    std::cout << car2.year << '\n';
    std::cout << car2.color << '\n';

    return 0;
}