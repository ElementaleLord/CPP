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
int main(){
    /*
    * we have 3 methods relevent to extracting characters from files
    ~   .getline(char * the-place-where-we-store-the-input, int the-number-of-bits-to-extract, char the-seperator/delimiter)
    ?   the first parameter of the .getline() method can also be an array of type char as the array name is a pointer
    ?   the second parameter of the .getline() method is the size/amount of character to extract unless you run into the sep char
        ex. we want the word "forest" thats 6 characters (aka. 6 bits) so its getline would be: file.getline(buffer, 6)
        sep char= seperator character
    ?   the third parameter of the .getline() method is the char on which it stops (this char is what seperates each extraction instance)
        of course getline stops once it reaches the previously specified size but what if it takes something we dont want
        ex. we want to extract a file by word that would look something like: file.getline(buffer, 50, ' ')
        the reason is theres always a space seperating each word so the method should get keep extracting characters
        till it gets to 50 total character or it hits a space 
        (as in here we assume that theres no words in file that are longer than 50 characters)
    ^   by default the third parameter of .getline() method is '\n'
        as that represents the end of the current line and start of the next line

    ~   .get(char * the-place-where-we-store-the-input, int the-number-of-bits-to-extract, char the-seperator/delimiter)
    ?   the first parameter of the .get() method can also be an array of type char as the array name is a pointer
    ?   the second parameter of the .get() method is the size/amount of character to extract unless you run into the sep char
        ex. we want the word "forest" thats 6 characters (aka. 6 bits) so its get would be: file.get(buffer, 6)
        sep char= seperator character
    ?   the third parameter of the .get() method is the char on which it stops (this char is what seperates each extraction instance)
        of course get stops once it reaches the previously specified size but what if it takes something we dont want
        ex. we want to extract a file by word that would look something like: file.get(buffer, 50, ' ')
        the reason is theres always a space seperating each word so the method should get keep extracting characters
        till it gets to 50 total character or it hits a space 
        (as in here we assume that theres no words in file that are longer than 50 characters)
    ^   by default the third parameter of .get() method is '\n'
    
    !   i hear you asking what the diference between get() and getline() is ? 
    ?   well .getline() extracts the seperactot and deletes it, .get() doesn't extract the seperator
    $   why is this important ? check the code after line 72 for you to understand

    ~   .ignore(int how-many-character-to-extract-and-TO-INGORE, char the-seperator/delimiter)
    ?   the first parameter of the .ingore() method specifies the number of charcter to extract and ignore
    ?   the second parameter of the .ingore() method specifies the sperator character
    ^   the seperator specified is also ignored. remember this!
        .ignore() is used most often alongside .get() overloaded function variant of the .get() method
    */
    std::fstream file_6;
    file_6.open("6.txt", std::ios::in);

    if (file_6.is_open()){
        std::cout << "File 6 has been opened properly" << std::endl;
        char buffer[50];

        //* an example of extracting a file line by line
        while (file_6.getline(buffer, 50)){
            //? alternate take on the old do-while loop using a while loop
            //^ the condition in this while loop is equivalent to: file_6.getline(buffer, 50, '\n')

            std::cout << buffer << std::endl;
        };

        file_6.clear();
        file_6.seekg(0);
        //? reseting reading position
        
        //* now rather than extract each line we want to extract only the initiales in 6.txt
        //^ get has an overloaded function in which we extract one character
        //  note that getline does not have an equivalent overloaded function to .get()
        char first_initial, second_initial;

        do{
            first_initial = file_6.get();
            //? this gets us the first initial on the line
                
            file_6.ignore(INT_MAX, ' ');
            //? we then ignore all charcters until the space inbetween names

            second_initial = file_6.get();
            //? this gets us the second initial on the line, what next?

            file_6.ignore(INT_MAX, '\n');
            //? so we ignore all characters until the end line character

            std::cout << first_initial << ". " << second_initial << '.' << std::endl;
        }while (!file_6.eof());

        //* now we want to extarct the full first name but only the last names initial
        file_6.clear();
        file_6.seekg(0);
        char first_name[50];

        do{
            file_6.get(first_name, 50, ' ');
            // file_6.getline(first_name, 50, ' ');
            second_initial = file_6.get();
            file_6.ignore(INT_MAX, '\n');
            //? as getline extracts and deletes the seperator (space in this case) 
            //? we don't have to ignore anything before extracting the last name initial
            //? but we do still have to ignore the rest of the last name
            //~ at this point if you ran the code or are actually reading the code
            //~ you would notice that were using get() instead of getline()
            //~ this is to show you the difference mentioned in line 45
            //$ now add '//' to the start of line 100 and remove '//' from the start of line 101 
            //$ then run your code and observe the difference in the output gained

            std::cout << first_name << ' ' << second_initial << '.' << std::endl;
        }while (!file_6.eof());

        file_6.close();
    }
    else{
        std::cout << "File 6 has NOT been opened properly" << std::endl;
    }

    //^ cin also has a .getline method. something to keep in mind ye?

    return 0;
}