#include <iostream>

double getTotal(double prices[], int size);

int main (){
    double prices[]= {49.99, 15.05, 75, 9.99};
    int size= sizeof(prices)/sizeof(prices[0]);
    double total= getTotal(prices, size);

    std::cout << "$" << total << std::endl;

    /*
    to pass an array to a function you only need the array name
    no need for [] but when a function receives the array
    the array decays into a pointer and the function
    can no longer knows the size of the array
    we could pass the size as a separate parameter of the function
    */

    return 0;
}
double getTotal(double prices[], int size){
    double total= 0;

    for (int i =0; i< size; i++){
        total+= prices[i];
    }

    return total;
}
