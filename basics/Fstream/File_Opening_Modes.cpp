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
    //* by default the file opening mode for fstream is ios:in | ios::out
    //? ios = input ouput stream

    //* to mod file modes we use FLAGS:
    /*
      ios::in = INPUT STREAM - READ MODE

      ios::out = OUTPUT STREAM - WRITE MODE
    ~           if there exists NO file with that name, create a file with that name, 
    ?   we use this quirk of ios::out to crete output files via the code rather than having the user create them themselves
    ~           if there is A file with that name truncate the file UNLESS this flag occurs with the ios::in flag

      ios::trunc = TRUNCATE - it is truncating the file (cutting everything inside)
    ? truncating something means to remove the old stuff and add the new stuff or in other words overwrite the old with the new

      ios::ate = At The End - it is setting the pointer at the end of file
    ~            the position of the pointer can be changed in this mode, it is possible to read and write in this mode

      ios::app = APPEND - the content is added at the end of file 
    ~            It is NOT possible to remove content nor adding something in any another place but the end of file in this mode

      ios::binary = opens the file as a binary file
    */

    //* there exist multiple defaults too there based on the variable type
    /*
    fstream = ios::in | ios::out
    ifstream = ios::in
    ofstream = ios::out
    */
    // it is best if u know at the start that from this file you only want to read or write use ifstream or ofstream resp.

    //* so to modify the opening mode you simply make use of the .open() method's second parameter
    std::fstream file_2;
    file_2.open("2.txt", std::ios::out); 
    // ^^^ this does create the file but overwrites the file if it exists
    // file_2.open("2.txt"); 
    // ^^^ this doesn't create the file and doesn't overwrite the file if it exists
    // file_2.open("2.txt", std::ios::out | std::ios::in | std::ios::ate); 
    // ^^^ this doesn't create the file and doesn't overwrite the file if it exists
    // file_2.open("2.txt", std::ios::out | std::ios::app);
    // ^^^ this does create the file and doesn't overwrite the file if it exists

    //~ for redding = .open("x.txt", std::ios::in)
    //~ for writing = .open("x.txt", std::ios::out)
    //~ for reading and writing = open.("x.txt") <default setting of fstream objects remember?>

    //$ run the code and observe that the file 2.txt is created 
    //  hint: you can use 'ctrl + / 'to turn the selected line thats not a comment into a comment or vise versa
    //$ delete 2.txt
    //$ now add at the start of line 55 a '//' then remove the a '//' from the start of line 53
    //$ observe as you get an error (that's bad BTW)

    //^ additionally its possible to open a file using the constructor
        {
        std::fstream file_1("1.txt", std::ios::in);
        // like this ^^^
        if (file_1.is_open()){ std::cout << "File 1 have been opened properly\n"; file_1.close(); }
        else{ std::cout << "File 1 hasn't been opened properly\n"; }
        }

    if (file_2.is_open()){
        std::cout << "File 2 have been opened properly\n";

        file_2 << "Sample text 1\n";
        file_2 << "Sample text 2\t";
        file_2 << "Sample text 3\n";

        //! but with just this isn't enough as we are still overwriting the file every time we run the code

        //* to add to the file instead of overwriting the content one way is to use ios::ate alongside ios::out and ios::in 
        //~ the syntax becomes = .open("x.type", std::ios::out | std::ios::in | std::ios::ate)
        //$ try adding a '//' at the start of line 57 then remove the '//' from the start of the current open line (should be 55)

        //* now that we know that way lets use the actual proper way to append content and thats with... the append tag
        //$ add a '//' at the start of the current open line (should be line 57) then remove the '//' from line 59 and run the code

        file_2.close();
    }
    else{
        std::cout << "File 2 hasn't been opened properly\n";
    }

    return 0;
}