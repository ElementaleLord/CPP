#include<iostream>

// object instantiation
class Human{
    public://public access modifier

        // attribute declaration / definition / instantiation

        std::string fname= "John";//assigning default attributes
        std::string lname= "Doe";
        std::string occupation;
        int age;

        // methods declaration / definition / instantiation

        void eat(){
            std::cout << "This person is eating\n";
        }
        void drink(){
            std::cout << "This person is drinking\n";
        }
        void sleep(){
            std::cout << "This person is sleeping\n";
        }    
};
class Car{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

        void accelerate(){
            std::cout << "GAS! GAS! GAS! IM GONNA STEP ON THE GAS!!!\n";
        }
        void brake(){
            std::cout << "SCREEEEEEEEEEEEEeeeeeeeeechhhhhhhhh\n";
        }
};

int main(){
    /*
    object = A collection of attributes and methods
             They can have characteristics and could perform actions
        Attributes = are an objects characteristics
        Methods    = are an objects actions
             Can be used to mimic real world items (ex. Phone, Book, Dog)
             Created from a 'class' which acts as a "blue-print"
    */
    /*
    To create an object we would use the name of the class
    then a unique identifier for the object
    syntax:

    object-typeNAME object-name;
    */
    Human human1;
    Human human2;
    Human human3;
    /*
    To access the attributes or methods of an object
    We use the (.)member access modifier 

    syntax for attributes:
    object-name.object-attribute= value;

    syntax for methods:
    object-name.object-method(argument/s);

    */
    // attribute assignment
    human1.fname= "Elementale";
    human1.lname= "Lord";
    human1.occupation= "Guardian";
    human1.age= 500;

    std::cout << human1.fname << ' ' << human1.lname << '\n';
    std::cout << human1.age << '\n';
    std::cout << human1.occupation << '\n';

    // method invocation
    human1.eat();
    human1.drink();
    human1.sleep();

    //added examples
    human2.fname= "Walter";
    human2.lname= "White";
    human2.age= 52;
    human2.occupation= "The Cook";

    std::cout << human2.fname << ' ' << human2.lname << '\n';
    std::cout << human2.age << '\n';
    std::cout << human2.occupation << '\n';
    
    human2.eat();
    human2.drink();
    human2.sleep();
    
    human3.age= 42;
    human3.occupation= "Retail";

    std::cout << human3.fname << ' ' << human3.lname << '\n';
    std::cout << human3.age << '\n';
    std::cout << human3.occupation << '\n';
    
    human3.eat();
    human3.drink();
    human3.sleep();

    Car car1;

    car1.make= "Picanto";
    car1.model= "KIA";
    car1.year= 2016;
    car1.color= "Brown";

    std::cout << car1.make << '\n';
    std::cout << car1.model << '\n';
    std::cout << car1.year << '\n';
    std::cout << car1.color << '\n';

    car1.accelerate();
    car1.brake();

    return 0;
}