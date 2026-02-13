#include<iostream>

int main(){
    /*
    Null value = a special value that means something has no value.
                 When a pointer is holding a null values.
                 that pointer is not pointing at anything (null pointer)

    nullptr = keyword represents a null pointer literal

    nullptr are helpful if an address was successfully assigned to a pointer
    */
   // when declaring a pointer its good practice
   // to have it point to a pointer ||or|| to a null pointer literal
    int *pointer= nullptr;
    int x= 123;
    pointer= &x;//turn this line to a comment
    /*
    -dereferencing a null pointer can lead to undefined behavior

    -what some programmers do is check if a pointer is null or not

    -there are some situations (like in dynamic memory)
    where attempting to assign a value to a pointer fails

    -if pointer is null then i have failed to
    assign an address to that pointer

    -if your pointer is still a null pointer it's not safe
    to dereference that pointer

    -if i need access to that values thats at that pointer
    it would be safe to do so within the else statement block
    */
    if(pointer == nullptr){
        std::cout << "Address was not assigned!\n";
        std::cout << *pointer << '\n';//this is undefined behavior
    }else{
        std::cout << "Address was assigned!\n";
        std::cout << *pointer << '\n';
    }

    return 0;
}