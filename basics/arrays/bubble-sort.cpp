#include <iostream>

void upSort(int array[], int size);
void downSort(int array[], int size);

int main(){
    /*
    bubble sort= start at index zero check 
                 if the element at the next index is greater than the current
                 transfer the element in the current index to a temp variable
                 transfer the element at the next index to the current index
                 transfer element in temp variable to next index
                 increase the starting index by 1 and repeat
        then repeat until sorted
    */
    int array[]= {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size= sizeof(array)/sizeof(array[0]);

    for(int i=0; i<size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    upSort(array,size);
    
    for(int i=0; i<size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    downSort(array,size);
        
    for(int i=0; i<size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

   return 0;
}
// ascending order sort
void upSort(int array[], int size){

    int temp;

    for(int i=0; i< size-1; i++){
        for(int j=0; j< size-i-1; j++){
            if(array[j] > array[j+1]){
                temp= array[j];
                array[j]= array[j+1];
                array[j+1]= temp;                
            }
        }
    }
}void downSort(int array[], int size){

    int temp;

    for(int i=0; i< size-1; i++){
        for(int j=0; j< size-i-1; j++){
            if(array[j] < array[j+1]){//its just this if statement thats different
                temp= array[j];
                array[j]= array[j+1];
                array[j+1]= temp;                
            }
        }
    }
}