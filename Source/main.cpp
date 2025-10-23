#include <iostream>
#include "parser.h"
#include "jsonParser.h"

int main(int argc, char* argv[]) {
    loadJson(); // charger le JSON au démarrage

    int ret = argparser(argc, argv);
    if(ret != 0) {
        std::cout << "Error: invalid command or missing parameters." << std::endl;
    } else {
        std::cout << "Task added successfully." << std::endl;
    }

    return 0;
}
