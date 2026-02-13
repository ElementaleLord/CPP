#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string text_t;
//typedef int number_t;
using number_t = int;

int main (){
    
    // typedef = reserved keyword used to crete an additional name
    //           (alias) for another data type. kinda like a nickname
    //           New identifier for an existing typedef
    //           Helps with readability and reduces types
    //           Use when there is a clear benefit
    //           Replaced with 'using' (work better w/templates)

    pairlist_t pairlist;
    text_t firstname= "patrick";
    cout << firstname << endl;
    number_t x= 5;
    cout << x << endl;


    return 0;
}