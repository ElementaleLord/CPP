#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main (){
    double balance = 0;
    int choice;
    do{
        std::cout << "*******************\n";
        std::cout << "1. Show Balance.\n";
        std::cout << "2. Deposit Money.\n";
        std::cout << "3. Withdraw Money.\n";
        std::cout << "4. Exit.\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "*******************\n";

        std::cin.clear();
        //this function will reset any error flags when the standard input
        // fails to interpret the input
        fflush(stdin);
        //flushes the '\n' left in the input buffer

        switch(choice){
            case 1:
                showBalance(balance);
                break;
            case 2: 
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                break;
            default:
            std::cout << "Invalid choice\n";
            }
    }while(choice!=4);


    return 0;
}
void showBalance(double balance){
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}
double deposit(){
    double amount=0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;
    if (amount > 0)
    {
    return amount;
    }
    else 
    {
    std::cout << "That's not a valid amount.\n";
    }
}
double withdraw(double balance){
    double amount= 0;
    std::cout << "Enter an amount to withdraw: ";
    std::cin >> amount;
    if (amount > balance)
    {
        std::cout << "Insufficient funds.\n";
        std::cout << "your balance is: " << balance << '\n';
    }
    else if (amount < 0)
    {
        std::cout << "That's not a valid amount.\n";
    }
    else 
    {
        return amount;
    }
}