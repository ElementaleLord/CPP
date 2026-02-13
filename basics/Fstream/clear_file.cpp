#include <iostream>
#include <fstream>

/*
if your using VSCode use the better comments extension so the tags below actually show different colors
follow the better-comments.txt file for instructions on how to integrate the proper setting configuration
! some problem we may run into.
$ instruction to-do yourself.
~ explaining the reason behind doing something.
* a title for the next section... kinda.
? elaborating previous line for greater clarity.
^ an important or/and crucial note.
*/
int main () {
    std::fstream file;
    //* simply opening the file in output mode then imediatly closing it is enough to clear the data inside the file
    file.open("8.txt", std::ios::out);
    if (!file){
        std::cerr << "error";
        exit(1);
    }
    file.close();
    //$ type/paste some text into 8.txt then run this code observe as 8.txt is cleared

    return 0;
}