#include<iostream>
// to use templates we have to use a template parameter declaration
template <typename T, typename U>//adding one or more templates
auto max(T x, U y){//T is a common naming convention think of it like T= this thing we need
    return (x > y) ? x: y;
}
//auto makes the compiler fit the best data type for the return
int main (){
    /*
    function templates = describes what a function looks like.
                         Can be used to generate as many overloaded functions
                         as needed, each using different data types
        its like a cookie cutter
        the cookies (functions) have the same shape
        but the dough(parameters) can alternate 
        within a set range(inputted parameters)
    */
   std::cout << max(1, 2.1) << '\n';
    return 0;
}