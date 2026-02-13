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
    * use the .bad() flag thats based on the badbit which returns true if there is an error and false otherwise
    ~ ex. writing to a file thats opened as-input-stream / in-read-mode (ios::in)

    * use the .fail() flag thats based on the failbit which returns true if we try to assign a string 
    *                        an integer while reading the file OR when badbit situation happens and false otherwise
    ? yes that means that failbit includes badbit + incompatible data typing

    * use the .eof() flag thats based on the eofbit which returns true when a file opened in read mode reaches its end

    * use the .good() flag thats based on the goodbit which returns true if everything is good false otherwise
    ~ in reality the good bit is false if ANY of the above flags are true

    * use the .rdstate() method to read the file state
    bad bit set is state 1  = 001
    failbit set is state 4  = 100
    eofbit set is state 2   = 010
    so if 1 then bad is set, if 2 then eof is set, if 4 then fail is set
    ^ we can sum these up to identify if more then one test bit is set
    if 3 then bad and eof are set, if 5 then bad and fail are set, if 6 then fail and eof are set, if 7 then all three are set
    * use the .clear() flag to clear the state of the file
    */
    std::fstream file_3("3.txt", std::ios::in);
    // std::fstream file_3("3.txt");

    if (file_3.is_open()){
        std::cout << "File 3 have been opened properly\n";

        file_3 << "Sample text 2";
        //$ observe that "Sample text 2" isn't added to 3.txt

        std::cout << "badbit= " << file_3.bad() << std::endl;
        //! if the badbit is set (!=0) then we can NOT perform anymore operations on the file
        //~ practical use case is in an if statement
        if (file_3.bad()){
            std::cerr << "an error occurred while writing to File 3.txt\n";
        }

        //* if you want to perform some legal operations after an error you have to clear the error state
        file_3.clear();

        std::string strBuffer;

        file_3 >> strBuffer;
        std::cout << strBuffer << std::endl;
        //$ observe in the terminal output that we have NO errors in this case (as we get the expected 'Sample')
        if (file_3.fail()){
            std::cout << "badbit is set or wrong type error\n";
            file_3.clear();
        }

        int intBuffer;
        file_3 >> intBuffer;
        std::cout << intBuffer << std::endl;
        //$ observe in the terminal output that we have an error in this case (as we get '0')
        if (file_3.fail()){
            std::cout << "badbit is set or wrong type error\n";
            file_3.clear();
        }

        file_3 >> strBuffer;
        std::cout << strBuffer << std::endl;
        //? thanks to the error the pointer has not moved so we have to do the above two lines to show the following

        file_3 >> intBuffer;
        std::cout << intBuffer << std::endl;
        //$ observe in the terminal output that we have NO errors now in this case (as we get the expected '1' which is an int)
        if (file_3.fail()){
            std::cout << "badbit is set or wrong type error\n";
            file_3.clear();
        }

        //* the above is one way to read from a file but its... bad so we need a solution which is loops obviously
        // but how to know when we reach the end of file ?
        // end of file => eof => the .eof() method
        // so we use the following
        do{
            //* its important to note that the file is being read word by word as we are using a string object
            file_3 >> strBuffer;
            std::cout << strBuffer << ' ';

            if (file_3.fail()){
                std::cout << "badbit is set or wrong type error\n";
                file_3.clear();
            }
        }while ( !file_3.eof() );
        //~ your smart enough to understand the above do-while loop if not go revise your do-while loops

        std::cout << std::endl << "goodbit= " << file_3.good() << std::endl;
        //  the goodbit is returning false
        //$ reread line 16 for the answer

        file_3.close(); 
    }
    else{ 
        std::cout << "File 3 hasn't been opened properly\n"; 
    }
















    std::ifstream file("better-comments.txt");
    char charBuffer;
    do{
        //* its important to note that the file is being read character by character as we are using a char variable
        file >> charBuffer;
        std::cout << charBuffer << ' ';
    }while(!file.eof());


    std::cout << std::endl << "file state=" << file.rdstate() << std::endl;
    //~ we have an ouput of 6 on the read state on file that means an eof and fail error has occurred
    //? this is bc an enter can't be mapped to a char and we have after the do-while loop reached the end of the file

    std::cout << "file state excluding eof= " << (file.rdstate() ^ std::ifstream::eofbit) << std::endl;


    //* if we reach the end of file clear state
    if ( (file.rdstate() ^ std::ifstream::eofbit) == 0){
        //? the above condition is checking if the error is an eof error or not
        // using the bit wise operator for exclusive OR ^

        file.clear();

        //! remember that the pointer is still at the end of file even if the state is cleared
        //*  change the pointer position to some other position in file
        //  and you can continue the file code after that
        //$ see reading_position_pointer.cpp and writing_position_pointer.cpp for how to do that
    }

    return 0;
}