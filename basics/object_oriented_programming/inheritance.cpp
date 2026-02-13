#include <iostream>

// a parent class
class Animal{
    public:
        bool alive= true;

    void eat(){
        std::cout << "this animal is eating\n";
    }
};
// a child class
class Dog : public Animal{
    public:
    void play(){
        std::cout << "this dog is playing\n";
    }
};
// another child class
class Cat : public Animal{
    public:
    void stare(){
        std::cout << "this cat is staring\n";
    }
};

int main(){
    /*
    inheritance = A class can receive attributes and methods from another class
                  Children classes inherit from a Parent class
                  Helps to reuse similar code from within multiple classes
    */
   /*
    to inherit from another class you would out the child class name
    then : then public then the name of the parent class 
    syntax:
    class Child-name : public Parent-name{};
   */
    // declaring an object
    Dog dog;
    /*
    displaying/invoking the parent class attribute/s 
    and method/s that the child class inherited
    */
    std::cout << dog.alive << '\n';
    dog.eat();
    // invoking method exclusive to this child class
    dog.play();

    //example of a second child class
    Cat cat;
    std::cout << cat.alive << '\n';
    cat.eat();
    //cat.play();// throws an error as play() is exclusive to the Dog child class
    cat.stare();// invoking stare() a method exclusive to the Cat class



    return 0;
}