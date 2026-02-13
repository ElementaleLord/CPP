#include <iostream>

int main()
{
    //switch = alternative to using many if else statements 
    //         compare one value against matching cases

    int month;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    switch (month){
        case 1: 
            std::cout << "It's January!";
            break;
        case 2: 
            std::cout << "It's February!";
            break;
        case 3: 
            std::cout << "It's March!";
            break;
        case 4: 
            std::cout << "t's April!";
            break;
        case 5: 
            std::cout << "It's May!";
            break;
        case 6: 
            std::cout << "It's June!";
            break;
        case 7: 
            std::cout << "IT's July!";
            break;
        case 8: 
            std::cout << "IT's August!";
            break;
        case 9: 
            std::cout << "IT's September!";
            break;
        case 10: 
            std::cout << "IT's October!";
            break;
        case 11: 
            std::cout << "IT's November!";
            break;
        case 12: 
            std::cout << "It's December!";
            break;
        default:
            std::cout << "Please enter in only numbers (1-12): ";
    };
    std::cout << std::endl << std::endl;

    char grade;

    std::cout << "Enter your grade: ";
    std::cin >> grade;

    switch(grade){
        case 'A':
            std::cout << "You did great!";
            break;
        case 'B':
            std::cout << "you did good";
            break;
        case 'C':
            std::cout << "You did okay";
            break;
        case 'D':
            std::cout << "You did not do good";
        case 'F':
            std::cout << "YOU FAILED!";
        default:
            std::cout << "Please only enter in a letter grade (A-F): ";
        
    };


    return 0;
}