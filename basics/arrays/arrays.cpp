#include <iostream>

int main (){
    /* array = a data structure that can hold multiple values
                values are accessed by an index number
                "kind of like a variable that holds multiple values"
    -------------------------------------------------------------------------
    Declare an array by adding [] next to the name.
    Example: int x[] <====> declaration of an integer  array called x
    To set the element of an array use {} after x[]=
    Example: int x[]={1, 2, 3} <====> (array called x of type integer and )
                                      (has 1 2 3 as elements inside it    )
    index refers to the number of the element of an array all array and array-like
    data structure start from index 0
    */
    // Tp example:
    std::string cars[] = {"Corvette", "Mustang", "Camry"};
    // ^^^ Declaring an array named car of type string ^^^
    std::cout << cars << std::endl;
    // ^^^ Displays the memory address of the array
    std::cout << cars[0] << std::endl;
    std::cout << cars[1] << std::endl;
    std::cout << cars[2] << std::endl;
    // ^^^ Displays the content of the specified index
    // values in an array have to be of the same type as the array
    // aka no int in a char array no string in an int array

    /*
    to add an element to an array you fist have to specify an array size
    this done by declaring int x[4] <====> an array named x of type integer and of size 4
    note: the reason we didn't have to do this in the above cars array was because
    we set the elements right away
    */
    //example to comprehend
    int x[5];

    x[0]=1;
    // ^^^ this isn't possible if we didn't specify a size for x before the above line
    //x[5]=2;   // is wrong bc the index starts from 0 so if size=5 ===> index can be 0 || 1 || 2 || 3 || 4
    // BUT IT CAN NOT BE 5 AS THAT INDEX TO THE PROGRAM DOESN'T EXIST
 
    return 0;
} 