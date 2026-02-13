#include <iostream>

namespace first{
    int x = 0;
}
namespace second{
    int x = 2;
}

int main (){
    // namespace = provides a solution for preventing name conflicts
    //             in large projects. Each entity needs a unique name.
    //             A namespace allows for identically named entities
    //             as long as the namespaces are different
    //  :: = scope resolution operator

    int x = 1;

    std::cout << x <<std::endl;
    std::cout << first::x <<std::endl;
    std::cout << second::x <<std::endl;

    return 0;
}