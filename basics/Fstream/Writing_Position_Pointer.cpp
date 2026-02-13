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
int main() {
    /*
    *    there are two methods for working with the writing pointer position:
    ~    tellp - tell put - tells where is the putting pointer
    ~    seekp - seek put - sets writing (putting) pointer at specified position

    ^    the following is the overloaded function syntax:
    ^    seekp(how_many_bytes_from_the_flag_place, flag);

    *    possible flags:
    ~    ios::beg - (begin) set from the begin (default)
    ~    ios::end - set from the end
    ~    ios::cur - (current) set from current place
    */
    std::fstream file_5;
    //^ seekp and tellp only work on ofstream and fstream objects. remember that!

    file_5.open("5.txt", std::ios::out);


    if (file_5.is_open()){
        std::cout << "File 5 have been opened properly\n";
        
        std::string tmp= "some sample string for sample stuff. idk what to write here :>";
        file_5 << tmp;
        file_5.tellp();

        //* we want to add an s after string in 5.txt which weknow is 18 from the beggining of file
        file_5.seekp(18);

        file_5 << "s ";
        //$ observe that the " f" after the word string are overwritten by "s " in 5.txt

        //* now lets say we want to make the first letter a capital letter
        file_5.seekp(0);

        file_5 << "S";
        //$ observe in 5.txt as we have a capital S at the start of file
        //~ how do we add stuff to file rather than overwrite ? havent figured out that part yet go look it up
        /* 
        ok so i asked copilot (the built-in ai) and the process involves you reading 
        the entire file then using a find function to get the position then using an 
        insert function to add your alteration while making sure to specifie the proper spacing 
        (with 'string' we have to specifie 6 positions to the right of where the find function position is)
        and after all that write to the file the modded content (aka overwrite the file)
        */


        std::cout << std::endl << file_5.rdstate() << std::endl;
        if ((file_5.rdstate() ^ std::ifstream::eofbit) == 0){
            file_5.clear();
        }

        file_5.close(); 
    }
    else{ 
        std::cout << "File 5 hasn't been opened properly\n"; 
    }

    return 0;
}