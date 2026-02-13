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
    *there are two function that operate on the reading pointer
    ~    tellg - tell get - tell where is the reading pointer
    ~    seekg - seek get - set reading pointer at specified position

    ^    the following is the overloaded function syntax:
    ^    seekg(how_many_bytes_from_the_flag_place, flag);

    *    possible flags:
    ~    ios::beg - (begin) set from the begin (default)
    ~    ios::end - set from the end
    ~    ios::cur - (current) set from current place
    */
    std::fstream file_4;
    //^ seekg and tellg only work on ifstream and fstream objects. remember that!

    file_4.open("4.txt", std::ios::in);


    if (file_4.is_open()){
        std::cout << "File 4 have been opened properly\n";
        std::string strBuffer;

        //* we want to know the size of the file

        file_4.seekg(0, std::ios::end);
        //? we seek to the end of file then move 0 from that position meaning we are at the end

        std::streampos sizeOfFile = file_4.tellg();
        //? tellg gives us in bites the position of the READING pointer 
        //^ so if we are at the end of file the byte number that's returned is the size of file no?

        std::cout << "The size of file is " << sizeOfFile << " bytes." << std::endl << std::endl;
        //! now lets say we want to extract and display the content in file
        //! the reading position is still at the end of file we have to reposition it

        //$ little experiment time if the line 52 is turned into a comment youll get no content output.
        //$ dont believe me ? try it then
        file_4.seekg(0);
        //? as ios::beg is the default its enought to just seek to the begining and move 0 from that position
        //^ note positive number move right from the position flag while negative ones move left from the postive flag

        do{
            file_4 >> strBuffer;
            std::cout << strBuffer << ' ';
        }while ( !file_4.eof() );

        std::cout << std::endl << file_4.rdstate() << std::endl;
        if ((file_4.rdstate() ^ std::ifstream::eofbit) == 0){
            file_4.clear();
        }

        file_4.close(); 
    }
    else{ 
        std::cout << "File 4 hasn't been opened properly\n"; 
    }

    return 0;
}