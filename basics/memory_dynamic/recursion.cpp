#include<iostream>

void iterWalk(int steps);
void recurWalk(int steps);

int main(){
    /*
    recursion = a programming technique where the function
                invokes itself from within
                break a complex concept into repeatable single steps

    (iterative vs recursive)
    advantages = less code and is cleaner
                 useful for sorting anf searching algorithms

    disadvantages = uses more memory
                    slower 

    if we dont have a base case (when we stop) we end up in an infinite loop
    we will encounter whats called a STACK-OVERFLOW
    when you invoke a function you add whats called a FRAME to the STACK
    when your stack is over loaded you will encounter a stack-overflow
    so thats one problem with recursion
    */
   iterWalk(100);
   recurWalk(100);
    return 0;
}
void iterWalk(int steps){
    for(int i= 0; i< steps; i++){
        std::cout << "you took " << i+1 << " steps!\n";
    }
}
void recurWalk(int steps){
    //first we need a base case (when do we stop)
    if(steps > 0){
        std::cout << "you take a step!\n";
        // this is a recursive approach as were invoking
        // the walk function from within itself
        recurWalk(steps - 1);
    }
}