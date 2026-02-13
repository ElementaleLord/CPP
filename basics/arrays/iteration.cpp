#include <iostream>

int main (){
    std::string students[]= {"Spongebob","Patrick","Squidward","Sandy"};
    //to display all element of an array i have to manually go through each index and cout it
    std::cout << students[0];
    //this is done better and easier through a for loop
    for (int i=0; i<3; i++){
        std::cout << students[i] << std::endl;
    }
    //the problem is if we add another element the lop only display till i<3 aka i=2
    // as i starts from 0 this means this above for loop only displays indexes 0, 1 and 2
    //instead of setting the limit manually in source we can do this:
    for (int i=0; i< sizeof(students)/sizeof(std::string); i++){
        std::cout << students[i] << std::endl;
    }
    // this second for loop insures that the whole array get looped through regardless of how many
    // elements are added or removed from the array 
    // unlike the first for loop which will always show index 0 1 2 even if they dont exist

    return 0;
}