#include <iostream>

struct Car{
    std::string model;
    int year;
    std::string color;
};
void printCar(Car car);
void paintCar(Car &car, std::string color);

int main (){
    /*
    when passing structs as arguments in a function
    there passed by VALUE not by reference

    if you need the original struct aka to pass by REFERENCE 
    use the & (address-of operator)
    */

    Car car1;
    Car car2;

    car1.model= "Mustang";
    car1.year= 2023;
    car1.color= "red";

    car1.model= "Kia";
    car1.year= 2018;
    car1.color= "brown";

    paintCar(car1, "silver");
    paintCar(car2, "gold");

    std::cout << &car1 << '\n';
    printCar(car1);
    std::cout << &car2 << '\n';
    printCar(car2);

    return 0;
}
// pass struct by VALUE
void printCar(Car car){
    std::cout << &car << '\n';
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}
// pass struct by REFERENCE
void paintCar(Car &car, std::string color){
    car.color= color;
}