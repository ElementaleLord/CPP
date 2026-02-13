#include <iostream>
#include <fstream>

/*
if your using VSCode use the better comments extension so the tags below actually show different colors
follow the better-comments text file for instructions on how to integrate the settings fully
! some problem we may run into
$ instruction to-do yourself
~ explaining the reason behind doing something
* a title for the next section... kinda
? elaborating previous line for greater clarity
^ an important or/and crucial note
*/
int main () {

    //* First start by declaring a variable of type std::fstream
    std::fstream file_1;

    //~ file_1 will act as our file in the context of the program 
    //? think of file_1 like an object/struct based variable that carries all the info related to the file


    //* to open a file we use the built in method .open("x.type")
    file_1.open("1.txt");
    
    //! now we may run into the problem that 1.txt doesn't exist
    //! if thats the case we have to create it FOR NOW manually do that
    //$ if 1.txt exist delete and re-create a blank version of it
    //~ using .open on file_1 makes it become 1.txt
    //^ make sure the file name is inside ("") double quotes
    //^ additionally specify the file TYPE at the end 
    //? like above we specify its a text file by adding '.txt' after the name

    //* you can use the method .is_open() to check if a file opened properly
    if (file_1.is_open()){
        std::cout << "file opened properly";
        //? to inform if the file has been opened or not

        //* to move a variable to the file we use '<<'
        file_1 << "This is a sample text\t";
        file_1 << "This is a sample text\n";
        file_1 << "This is a sample text";

        //~ the same as cout << "This is sample text"
        // the output in this case is the file instead of the compiler interface / terminal
        //^ everytime this code is run 1.txt has its content overwritten by the above text


        //* to close the file use the method .close()
        file_1.close();
        //$ run the code then go check 1.txt it now should have text in it
    }

    //~ we close files when not in use to save on memory think of dynamical allocation
    // .close() is to fstream what delete pVar is to the dynamically allocated variable

    //^ as we free-d file_1 we can now use it to access another file instead of 1.txt

    return 0;
}