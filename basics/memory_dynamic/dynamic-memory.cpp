#include<iostream>

int main(){
    /*
    dynamic memory = Memory tht is allocated after the program
                     is already compiled & running.
                     Use the 'new' operator to allocate
                     memory in the heap rather than the stack

                     Useful when we don't know how much Memory
                     we will need. Makes out programs more flexible,
                     especially when accepting user input.
    */
    /*
    its good practice when you declare a pointer
    but dont assign it right away to give it a value
    of NULL meaning no value
    */
    int *pNum= NULL;
    /*
    to allocate memory in the heap rather than the stack:
    1. take my pointer
    2. set this equal to
    3. use the 'new' operator
    4. then a data type
    */
    pNum = new int;
    /*
    the 'new' operator is returning an address
    we store this address in the pointer
    its pointing to a memory location
    where we will store the specified data type later
    */
    /*
    later on in the program whenever you would like to store
    a value we use:
    1. the (*)dereference operator
    2. our pointer
    3. then assign a value
    */
    *pNum= 21;
    //displaying the address and value of the address stored in pNum
    std::cout << "address: " << pNum << '\n';
    std::cout << "value: " << *pNum << '\n';

    /*
    it's VERY GOOD practice if not EXPECTED whenever
    you use the 'new' operator you will also want to
    use the 'delete' operator when your
    no longer using that memory space
    so at the end of this program or early if you chose
    we will delete our pointer
    */
    delete pNum;// freeing the memory location in the heap from pNum
    /*
    were freeing up the memory at this address if you don't
    you may cause a memory leak and it's best to avoid that
    whenever you use the 'new' operator you should be
    using the 'delete' operator some place within your program
    */
    //example of dynamic array
    char *pGrades= NULL;
    int size;

    std::cout << "How many grades to enter in ?: ";
    std::cin >> size;
    pGrades= new char[size];
    for(int i= 0; i< size; i++){
        std::cout << "Enter grade #" << i+1 << ": ";
        std::cin >> pGrades[i];
    }
    std::cout << '\n';
    for(int i= 0; i< size; i++){
        std::cout << pGrades[i] << ' ';
    }
    std::cout << '\n';

    delete[] pGrades;//freeing a memory location from an array

    return 0;
}