#include "parser.h"
#include "jsonParser.h"

int argparser(int argcount, char* arg[]) {
    if(argcount < 2) return 1;

    std::string cmd(arg[1]);
    
    if(cmd == "add") {
        if(argcount < 3) return 1;
        std::string desc(arg[2]);
        jsParser("", desc, "todo", 1);
    } else if(cmd == "update") {
        if(argcount < 4) return 1;
        std::string id(arg[2]);
        std::string desc(arg[3]);
        jsParser(id, desc, "todo", 2);
    } else if(cmd == "delete") {
        if(argcount < 3) return 1;
        std::string id(arg[2]);
        jsParser(id, "", "todo", 3);
    
    } else if(cmd == "mark") {
        if(argcount < 4) return 1;
        std::string status(arg[2]);
        std::string id(arg[3]);
        if(status=="done"){
            jsParser(id, "", status, 4);
        } else if(status=="todo"){
            jsParser(id, "", status, 4);
        } else if(status=="in-progress"){
            jsParser(id, "", status, 4);
        }
    
    } else if(cmd == "list") {
        if(argcount < 3){
           jsParser("","","", 5); // toutes les tâches
        } else {
            std::string status(arg[2]);
            jsParser("", "", status, 6); // filtrage par status
        }
    }
     else {
        return 1;
    }
    return 0;
}
