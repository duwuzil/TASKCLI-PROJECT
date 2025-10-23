#include "parser.h"
#include "jsonParser.h"

int argparser(int argcount, char* arg[]) {
    if(argcount < 2) return 1; // pas de commande

    std::string cmd(arg[1]);
    if(cmd == "add") {
        if(argcount < 3) return 1; // pas de description
        std::string desc(arg[2]);
        jsParser("", desc, "todo", 1);
    } else {
        return 1; // commande inconnue
    }
    return 0; // succès
}
