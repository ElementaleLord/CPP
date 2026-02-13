#include <iostream>
#include <ctime>

int main(){
    //pseudo-random = NOT truly random (but close)

    srand(time(NULL));

    int num1= rand();
    std::cout << num1 << '\n';

    int num2= (rand() % 6)+1;
    std::cout << num2 << '\n';

    int num3= (rand() % 4)+1;
    std::cout << num3 << '\n';

    int num4= (rand() % 20)+1;
    std::cout << num4 << '\n';

    int num5= (rand() % 12)+1;
    std::cout << num5 << '\n';
    
    int num6= (rand() % 100)+1;
    std::cout << num6 << '\n';

    int dice1=(rand()%6)+1,dice2=(rand()%6)+1,dice3=(rand()%6)+1;
    std::cout << dice1 << ' ' << dice2 << ' ' << dice3 << '\n';

    return 0;
}