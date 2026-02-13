#include <iostream>
int main () {
    // foreach loop = loop that eases the traversal over an
    //                iterable data set

    //having the following array
    std::string students[]= {"Spongebob","Patrick","Squidward","Sandy"};
    //using a standard for loop i need THREE conditions as shown below
    for (int i=0;        i<sizeof(students)/sizeof(std::string);      i++){
        std::cout << students[i] << std::endl;
    }
    // this works fine and is ""very"" flexible
    // in a foreach loop there less syntax to write but its also less flexible unlike normal for looped
    // as in a for loop we can go forward backward or skip through iterations
    // with a foreach loop we start at the beginning and end at the end nothing else
    /*
    foreach loop syntax :
    for(type variable : iterable-data-set){

    }
    */
    for(std::string student : students){
        std::cout << student << std::endl;
        //note the differences from above
    }

    return 0;
}