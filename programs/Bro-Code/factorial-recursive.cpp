#include<iostream>

int iterFact(int num);
int recurFact(int num);

int main(){
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << iterFact(num) << '\n';
    std::cout << recurFact(num) << '\n';

    return 0;
}
int iterFact(int num){
    int res=1;
    for (int i= 1; i<= num; i++){
        res*= i;
    }
    return res;
}
int recurFact(int num){
    if (num == 1 || num == 0){
        return 1;
    }
    return num * recurFact(num - 1);
}