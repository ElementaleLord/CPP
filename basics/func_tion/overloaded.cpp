#include <iostream>

void bakePizza();
void bakePizza(std::string topping);
void bakePizza(std::string topping, int size);

int main()
{   
    // function can share the same name so long as they have different 
    // a function's name and it's parameters is called a function signature
    std::string top= "peperoni";
    int s= 5;
    bakePizza();
    bakePizza(top);
    bakePizza(top, s);

    return 0;
}
void bakePizza(){
    std::cout << "Here's your pizza!\n";
}
void bakePizza(std::string topping){
    std::cout << "Here's your "<< topping <<" pizza!\n";  
}
void bakePizza(std::string topping, int size){
    std::cout << "Here's your size "<< size << ',' << topping <<" pizza!\n";  
}