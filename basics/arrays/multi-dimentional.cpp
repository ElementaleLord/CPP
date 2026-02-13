#include<iostream>

int main (){
    // declaring a 2-D array requires two [] after the array name the first is rows he second columns
    std::string cars[3][4]= {{"Mustang", "Escape", "f-150"},
                            {"Corvette", "Equinox", "Silverado"},
                            {"Challenger", "Durango", "Ram 1500"}};
    // a 2D array is just a array where each of its elements are there own array
    int rows= sizeof(cars)/sizeof(cars[0]);
    int column= sizeof(cars[0])/sizeof(cars[0][0]);
    // displaying 2D arrays
    for(int i= 0; i< rows; i++){
        for(int j= 0; j< column; j++){
            std::cout << cars[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}