#include "jsonParser.h"
int x=0;

std::ifstream fileToRead("data/data.json", std::ifstream::binary);
Json::Value task;
fileToRead >> task;
if (!file.is_open()) {
    std::ofstream outfile ("data/data.json");
    outfile.close();
}

std::string jsParser(std::string id = "",std::string desc = "",std::string status="todo",int cd){
    if(cd == 1){
        std::string s = std::to_string(x);
        while(task[s]){
            x++;
        } else {
            task[s] = Json::Value();
            task[s]["desc"] = desc;
            task[s]["status"] = status;
            task[s]["createdAt"] = "DD/MM/AA:HH/mm";
            task[s]["updatedAt"] = "";
            x=0;
        }
    }
}

file.close();