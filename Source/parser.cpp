#include "parser.h"

int argparser(int argcount, char* arg[]){
    std::string cmd(arg[1]);
    if(cmd == "add"){
        std::string desc(arg[2]);
    } else if (cmd == "update"){
        std::string ID(arg[2]);
        std::string newdesc(arg[3]);
        //send this to json parser
    } else if (cmd == "delete"){
        std::string ID(arg[2]);
        //send this to json parser
    } else if (cmd == "mark"){
        std::string statut(arg[2]);
        std::string ID(arg[3]);
        //send this to json parser
    } else if (cmd == "list"){
        std::string status(arg[2]);
        //send this to json parser
    }
    else {
        return -1;
    }
}