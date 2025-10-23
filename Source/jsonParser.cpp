#include "jsonParser.h"
#include <fstream>


int x = 0;
Json::Value task;

// Charger le JSON depuis le fichier
void loadJson() {
    std::ifstream fileToRead("data.json", std::ifstream::binary);
    if (!fileToRead.is_open()) {
        std::ofstream outfile("data.json");
        outfile.close();
    } else {
        fileToRead >> task;
        fileToRead.close();
    }
}

// Sauvegarder le JSON dans le fichier
void saveJson() {
    std::ofstream fileToWrite("data.json");
    fileToWrite << task;
    fileToWrite.close();
}


std::string jsParser(std::string id, std::string desc, std::string status, int cd) {
    if (cd == 1) { 
        std::string s = std::to_string(x);
        while (task[s]) {
            x++;
            s = std::to_string(x);
        }
        task[s]["desc"] = desc;
        task[s]["status"] = status;
        task[s]["createdAt"] = "DD/MM/AA:HH/mm";
        task[s]["updatedAt"] = "";
        saveJson();
        x = 0;
    }
    else if(cd == 2) {
        if(task[id]){
            task[id]["desc"] = desc;
            saveJson();
        }
    }else if(cd == 3) {
        if(task[id]){
            task.removeMember(id);
            saveJson();
        }
    }
    else if(cd == 4) {
        if(task[id]){
            task[id]["status"] = status;
            task[id]["updatedAt"] = "DD/MM/AA:HH/mm";
            saveJson();
        }
    }
    //cmd 5 need to be implemented with main.cpp as it will list tasks
    return "";
}
