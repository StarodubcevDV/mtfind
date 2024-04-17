#include <iostream>


int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "Invalid input parameters! Expected parameters: {filename} {mask}"<< std::endl;
        return -1;
    }

    std::cout << "HELLO WORLD "<< argv[1] << std::endl;
    
    return 0;
}