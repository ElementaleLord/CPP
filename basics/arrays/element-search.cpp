#include <iostream>

int searchArray(int array[], int size, int element);

int main(){
    int numbers[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size= sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int myNum;

    std::cout << "Enter element to search for: " << std::endl;
    std::cin >> myNum;

    index= searchArray(numbers, size, myNum);

    if(index != -1){
        std::cout << myNum << " is at index " << index << std::endl;
    }else{
        std::cout << myNum << " is not in the array" << std::endl;
    }

    return 0;
}
int searchArray(int array[], int size, int element){
    // this is called a linear search
    // linear search= start at index 0 if equal to goal then get index
    //                if not move to the next index till you hit the last index
    for (int i=0; i< size; i++){
        if(array[i]==element){
            return i;
        }
    }
    return -1;
}