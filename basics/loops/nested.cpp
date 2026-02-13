#include <iostream>

int main ()
{
    // nested loop = a loop inside another loop
    for (int i =1; i<= 3; i++){
        for (int j=1; j<=10; j++){
            std::cout << j << ' ';
        }
    }
    std::cout << "\n\n\n";
    int rows, columns;
    char symbol;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    std::cout << "Enter the symbol: ";
    std::cin >> symbol;

    for (int i =1; i<= rows; i++){
        for (int j=1; j<= columns; j++){
            std::cout << symbol;
        }
        std::cout << '\n';
    }
}