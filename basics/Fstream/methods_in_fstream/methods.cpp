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
    //! big empty gapes indicate a new section meaning another method
    /*
    * the following is a section explaining what the .read() method of fstream standard library is
    ~ .read(char* ouput, int size-of-read)
    ^ the variable should be of type fstream or ifstream if its a file
    ^ the file should be opened in binary mode using ios:binary
    ? the first parameter of the .read() method specifies where the read ontent is sent/stored
    ? the second parameter of the .read() method specifies the size (in bytes) of the read content 
        aka. how many characters to read
    */

    //* we will first read from a file opened in binary mode
    std::fstream file;
    file.open("read.txt", std::ios::in | std::ios::binary | std::ios::ate);

    if (file.is_open()){
        std::cout << "File read has been opened properly" << std::endl;

        int sizeOfFile = file.tellg();
        //? as we want to read the whole file we get the size of file by using tellg 
        //^ do note that we opened the file with ios::ate (ate = at the end)

        char* pBuffer = new char[sizeOfFile];
        //? just using dynamic alocation instead of a static array

        file.seekg(0);

        file.read(pBuffer, sizeOfFile);

        std::ofstream out("readOUTbinary.txt");
        //? opening where we will dump the pBuffer thats full of the read content

        if(!out){
        //? the doctors recommended way of checking file opening errors
            std::cerr << "readOutbinary didnt open." << std::endl;
            exit(1);
        }
        out << pBuffer;

        //* freeing memory
        delete[] pBuffer;
        out.close();
        file.close();
    }
    else{
        std::cout << "File read has NOT been opened properly" << std::endl;
    }
    //$ if you run the code and open readOUTbinary.txt you would observe that the read() methods ouput comes with some additions

    //* now lets read from a file opened in a non-binary mode
    file.open("read.txt", std::ios::in | std::ios::ate);

    if (file.is_open()){
        std::cout << "read.txt has been opened properly" << std::endl;

        int sizeOfFile = file.tellg();
        //^ do note that we opened the file with ios::ate (ate = at the end)

        char* pBuffer = new char[sizeOfFile];

        file.seekg(0);

        file.read(pBuffer, sizeOfFile);

        std::ofstream out("readOUT.txt");
        //? opening where we will dump the pBuffer thats full of the read content

        if(!out){
        //? the doctors recommended way of checking file opening errors, i will try to use this from now on
            std::cerr << "readout didnt open." << std::endl;
            exit(1);
        }
        out << pBuffer;
        
        //* freeing memory
        delete[] pBuffer;
        out.close();
        file.close();
    }
    else{
        std::cout << "read.txt has NOT been opened properly" << std::endl;
    }















    /*
    * the following is a section explaining what the .put() method of fstream standard library is
    ~ .put(char character_to_put_in_stream)
    ^ the variable should be of type fstream or ofstream if its a file
    ? the first parameter of the .put() method specifies the character to add to the stream
    */
    // heres an example pn cout before we do this on a file
    std::string txt= "thistextisconnected";
    for (int i= 0; i < txt.length(); i++){
        std::cout.put(txt[i]).put(' ');
        //$ run the code and interpret the terminal output
    }
    // example on how the .put() method is used on files
    file.open("example_Put.txt", std::ios::out | std::ios::binary);

    if (!file){
        std::cerr << "example_Put.txt didnt open properly" << std::endl;
        exit(1);
    }
    
    char c;

    do{
        c= std::cin.get();
        file.put(c);
    }while(c!='.');
    file.close();
    //$ open exampel_Put.txt















    /*
    * the following is a section explaining what the .peek() method of fstream standard library is
    ~ .peek()
    ? no parameter for this method which returns the first character in stream WITHOUT extracting it from stream
    */
    //? the following example is done on iostream but the same principle applies to fstream
    // write a block of code that take user input then validates if its an int or str then display an appropriate message
    std::cin.ignore(INT_MAX, '\n');
    char temp= std::cin.peek();
    if(temp > '0' && temp < '9'){
        int number;
        std::cin >> number;
        std::cout << "Number is: " << number << std::endl;
    }
    else{
        std::string txt;
        std::cin >> txt;
        std::cout << "Text is: " << txt << std::endl;
    }















    /*
    * the following is a section explaining what the .putback() method of fstream standard library is
    ~ .putback(char charate_to_put_IN_stream)
    ? the first parameter of the .putback() method specifies the character which to return to the stream
    */
    //? the following example is done on iostream but the same principle applies to fstream
    // write a block of code that take user input then validates if its an int or str then display an appropriate message
    std::cin.ignore(INT_MAX, '\n');
    temp= std::cin.get();
    std::cin.putback(temp);
    if(temp > '0' && temp < '9'){
        int number;
        std::cin >> number;
        std::cout << "Number is: " << number << std::endl;
    }
    else{
        std::string txt;
        std::cin >> txt;
        std::cout << "Text is: " << txt << std::endl;
    }
    //$ notice that the above code is the same as in the .peek() section except for the modified second and added third lines
    /*
    now the question is when to use .peek() and when to use the .get() .putback() combo ?
    it largely depends on the situation your in but its good to note
    that .peek() would always have a faster run time
    then a character being extracted and returned to the stream
    */















    /*
    * the following is a section explaining what the .write() method of fstream standard library is
    ^ the variable should be of type fstream if its a file 
    ^ preferably opened in binary mode using ios::binary
    ~ .write(char* pointer_to_character_buffer, int number_of_characters)
    ? the first parameter of the .write() method specifies the buffer from which to take characters and write them on file
    ? the second parameter of the .write() method specifies the number of bytes (characeters) we want to write from source
    */
    file.open("write.txt", std::ios::out | std::ios::binary);

    if(!file){
        std::cerr << "write.txt didnt open properly" << std::endl;
    }
    char sample[]= "Sample text";
    file.write(sample, sizeof(sample));
    file.close();
    /*
    $ open the write.txt file and notice that the \0 (null character) was written as well
    ^ its best to set the second parameter as sizeof(string_object) - 1
      ex. outputing data to a file that used by people not machines
    ^ unless you need the \0 (null character) in this case you do what is done above
      ex. outputting to file that being written on and read from by multiple machines so knowing where the string ends is a requirement
    ! weird thing i ran into if the type of sample is char* the code wont work but if its char[] it does idk why that is
    ~ this is copilots summary on it so here learn something to watch out for:
        •Character Array: sizeof(sample) gives the total size of the array, including the null terminator.

        •Pointer to Character: sizeof(sample) gives the size of the pointer, not the size of the data. 
            Use strlen(sample) from the cstring library to get the length of the string.
    */















    /*
    * the following is a section explaining what the .gcount() method of fstream standard library is
    ^ the variable should be of type fstream if its a file
    ~ .gcount()
    ~   get character count || get the count of the extracted characters from the last extraction operation
        with functions like: .read(), .getline(), .ignore() etc...
    ? the first parameter of the .gcount() method specifies
    */
    file.open("read.txt", std::ios::in | std::ios::binary);
    
    if (!file){
        std::cerr << "read.txt did not open properly" << std::endl;
    }

    char buffer[50];

    do{
        file.getline(buffer, sizeof(buffer), ' ');

        std::cout << file.gcount() << " " << buffer << std::endl;
        file.getline(buffer, sizeof(buffer), ' ');

        std::cout << file.gcount() << " " << buffer << std::endl;
        file.getline(buffer, sizeof(buffer));

        std::cout << file.gcount() << " " << buffer << std::endl;

    }while(!file.eof());

    file.close();

    //! BELOW IS A TEMPLATE, IGNORE IT.
    /*
    * the following is a section explaining what the .() method of fstream standard library is
    ^ the variable should be of type fstream if its a file
    ~ .()
    ? the first parameter of the .() method specifies
    */

    return 0;
}