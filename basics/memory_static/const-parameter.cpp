#include<iostream>

void printInfo(const std::string name, const int age);

int main(){
    // const parameter = parameter that is effectively read-only
    //                   code is more secure & conveys intent
    //                   useful for references and pointers
    std::string name= "Patrick";
    int age= 20;

    printInfo(name, age);

    return 0;
}
void printInfo(const std::string name, const int age){
    /*
    An example of something we dont want happening 
    */
    //name= " ";
    //age= 0;
    /*
    The above even gives you an error' isn't IntelliSense helpful ?
    With normal parameters this function would have display the following:
    Name:  
    Age: 0
    But thanks to const parameter it displays well run the code and see
    */
    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
}