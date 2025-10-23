#include "jsonParser.h"
#include <fstream>
#include <jsoncpp/json/json.h>

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

// Fonction jsParser pour ADD uniquement
std::string jsParser(std::string id, std::string desc, std::string status, int cd) {
    if (cd == 1) {  // ADD
        std::string s = std::to_string(x);
        while (task[s]) {  // si la clé existe
            x++;
            s = std::to_string(x);
        }
        task[s]["desc"] = desc;
        task[s]["status"] = status;
        task[s]["createdAt"] = "DD/MM/AA:HH/mm";
        task[s]["updatedAt"] = "";
        saveJson();
        x = 0;
        return s;
    }
    return "";
}
