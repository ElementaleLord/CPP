#include <iostream>
#include <fstream>
#include "string.h"


bool AreFilesEqual(std::fstream *, std::fstream *);
int sizeOfFile(std::fstream *);

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
    std::fstream file_6, file_7;
    
    //! so this works only if we include ios::binary bc of the .read() method being funky with non-binary files
    //$ if you want to see it i have kept the code comented out in the second if statement inside the AreFilesEqual() function
    file_6.open("6.txt", std::ios::in | std::ios::binary | std::ios::ate);
    file_7.open("7.txt", std::ios::in | std::ios::binary | std::ios::ate);

    if (!file_6 || !file_7){
        std::cerr << "The file 6 or 7 has not been opened properly.";
        exit(1);
    }
    else{
        if( AreFilesEqual(&file_6, &file_7)){
            std::cout << "The files 6 and 7 are equal." << std::endl;
        }
        else{
            std::cout << "The files 6 and 7 are NOT equal." << std::endl;
        }
    }

    file_6.close();
    file_7.close();

    return 0;
}

bool AreFilesEqual(std::fstream *a, std::fstream *b){
    int fileSize1 = sizeOfFile(a);
    int fileSize2 = sizeOfFile(b);
    //^ a and b are pointer that are holding an address 
    //^ so theres no need to send (&a || &b) just send in (a || b)
    //^ aka the address thats pointed too by (a || b)

    if (fileSize1 != fileSize2){
        //? if the size of one file is not equal to the size of the other file then the files can NEVER be equal.
        return false;
    }

    //! this tho isn't enough because while the sizes may be equal the content may not
    
    //* we will use the memcmp() function which stands for memory compare (must incluse string.h)

    //! what if the file size is big 
    // ex. 3 GB, storing 3 gigs worth of var (even as a temp var) in memory is... well some dont have that RAM capacity

    //* solution segment the file into 1mb sections
    int BUFFER_SIZE;
    const int ONE_MB = 1024;

    if (fileSize1 > ONE_MB){
        BUFFER_SIZE = ONE_MB;
    }
    else{
        BUFFER_SIZE = fileSize1;
    }

    char* file1Buffer = new char[BUFFER_SIZE];
    char* file2Buffer = new char[BUFFER_SIZE];
    
    //! bc we are segmenting the big files we gotta repeat the below checks
    /*
    we need to repeat => some loop
    do we know the number of loops? no => while loop or do-while loop
    we want the code to run at least once first? yes => do-while loop
    */

    do{
        a->read(file1Buffer, BUFFER_SIZE);
        b->read(file2Buffer, BUFFER_SIZE);
        
        if ( memcmp(file1Buffer, file2Buffer, BUFFER_SIZE) != 0 ){
            //? memcmp is only false when its not equal to zero 

            //~ the output of memcmp = 0 if first == second, 1 if first > second and -1 if first < second

            //! dynamic vars arent freed if the return has to be false 
            //^ so make sure to check where your dynamic vars are being freed

            /*
            also the reason we dont have to free the memory in the previous if statement
            is because we havent alocated any dynamic vars at that point
            so theres no dynamic memory to free
            */

            //* the below three lines are for figuring out why the code wasnt working (before i thought to add ios::binary)
            // std::cout << file1Buffer << std::endl << std::endl;
            // std::cout << file2Buffer << std::endl << std::endl;
            // std::cout << memcmp(file1Buffer, file2Buffer, BUFFER_SIZE) << std::endl;

            delete[] file1Buffer;
            delete[] file2Buffer;
            
            return false;
        }

    }while(a->good() && b->good());

    //* the below three lines are for figuring out why the code wasnt working (before i thought to add ios::binary)
    // std::cout << file1Buffer << std::endl << std::endl;
    // std::cout << file2Buffer << std::endl << std::endl;
    // std::cout << memcmp(file1Buffer, file2Buffer, BUFFER_SIZE) << std::endl;

    delete[] file1Buffer;
    delete[] file2Buffer;

    return true;
}

//* we need the file size to do an initial check
int sizeOfFile(std::fstream *file){

    file->seekg(0, std::ios::end);
    int size_of_file = file->tellg();
    file->seekg(0, std::ios::beg);

    return size_of_file;
}