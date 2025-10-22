#include <iostream>
#include "parser.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " COMMAND" << std::endl;
        return 1;
    }
    int rep = argparser(argc, argv);
    switch (rep){
        case 1:
        std::cout << "ADD LU" << std::endl;
        break;
        default:
        std::cout << "commande non éxistente" << std::endl;
    }
    return 0;
}