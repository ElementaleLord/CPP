#include <iostream>

class Stove{
    /*
    previously we would use the public access modifier 'public:'
    then write any attributes 
    
    public:
        int temperature= 0;
    
    since the attribute named temperature is public its access-able outside the class
    it means that people can change it
    but we dont want that so lets set it to private 
    by using the private access modifier 'private:'
    */
    /*
    to write a getter we specify the return type then
    use get followed by the private attribute name 
    capitalized for better distinction
    syntax:
    data-type getAttribute-name(){
        return attribute-name;
    }
    */
    private:
        int temperature= 1;
    
    public:
    // a constructor that uses a setter
    Stove(int temperature){
        setTemperature(temperature);
    }
    // a getter
    int getTemperature(){
        return temperature;
    }
    // a setter
    void setTemperature(int temperature){
        /*
        U can make additional checks in a setter
        or even a getter if you (have||need||want) to
        */
        if(temperature < 0){
            this->temperature= 0;
        }else if(temperature > 10){
            this->temperature= 10;
        }else {
            this->temperature= temperature;
        }
    }

};

int main(){
    /*
    Abstraction = hiding unnecessary data from outside a class
    getter = function that makes a private attribute READABLE
    setter = function that makes a private attribute WRITEABLE
    */
    Stove stove(2);
    //stove.temperature= 1000000;
    //this above line throws an error bc temperature is a private attribute
    /*
    to display the temperature we use the getter
    Note: getter are just functions in the class meaning
    we call/use them like a normal method
    */
    std::cout << "The temperature setting is: " << stove.getTemperature() << '\n';
    /*
    to modify the temperature we use the setter
    Note: setter are just functions in the class meaning
    we call/use them like a normal method
    */
   stove.setTemperature(-3);
    std::cout << "The temperature setting is: " << stove.getTemperature() << '\n';

   stove.setTemperature(10000000);
    std::cout << "The temperature setting is: " << stove.getTemperature() << '\n';

    return 0;
}