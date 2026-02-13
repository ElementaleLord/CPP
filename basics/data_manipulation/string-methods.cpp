#include <iostream>

int main ()
{
    std::string name="patrick";
    /*
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    */
    // .length() = return the length of a string
    if (name.length() > 12){
        std::cout << "Your name can't have over 12 characters." << std::endl;
    }else{
        std::cout << "Welcome " << name << std::endl;
    }
    // .empty() = return a boolean true if the string is empty
    if (name.empty()){
        std::cout << "You didn't enter your name" << std::endl;
    }else{
        std::cout << "Welcome " << name << std::endl;
    }
    // .clear() = clears the string of its input
    name.clear();
    std::cout << "Welcome " << name << std::endl;
    // .append() = appends/adds to the string what-ever is in ()
    name.append("element");
    std::cout << "Welcome " << name << std::endl;
    // .at(i) = returns the character in the specified index i in the string
    std::cout << name.at(0) << std::endl;
    // .insert(i, "x") = inserts x in the specified index i in the string
    std::cout << name.insert(0, "@") << std::endl;
    // .find(' ') = returns the index of the first character in the string that matches the specified char
    std::cout << name.find('e') << std::endl;
    // .eraser(i, j) = erases the part of the string between index i and index j
    // i is inclusive but j is exclusive (meaning the erased part is actually from i to j-1)
    name.erase(0, 5);
    std::cout << name << std::endl;
 

}