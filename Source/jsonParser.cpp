#include "jsonParser.h"
#include "main.h"
#include <fstream>
#include <string>
#include <ctime>

int x = 0;
Json::Value task;
jsData dat; // définition réelle


// Charger le JSON depuis le fichier
void loadJson() {
    std::ifstream fileToRead("data.json", std::ifstream::binary);
    if (!fileToRead.is_open()) {
        // fichier inexistant → créer et initialiser à objet vide
        task = Json::Value(Json::objectValue);
        std::ofstream outfile("data.json");
        outfile << task; // écrire objet vide {}
        outfile.close();
    } else {
        if (fileToRead.peek() == std::ifstream::traits_type::eof()) {
            // fichier vide → initialiser à objet vide
            task = Json::Value(Json::objectValue);
        } else {
            fileToRead >> task; // parser normalement
        }
        fileToRead.close();
    }
}

// Sauvegarder le JSON dans le fichier
void saveJson() {
    std::ofstream fileToWrite("data.json");
    fileToWrite << task;
    fileToWrite.close();
}

std::string jsParser(std::string id, std::string desc, std::string status, int cd,int special) {
    time_t timestamp;
    time(&timestamp);
    if (cd == 1) { 
        // Ajouter une nouvelle tâche
        std::string s = std::to_string(x);
        while (task[s]) {
            x++;
            s = std::to_string(x);
        }
        task[s]["desc"] = desc;
        task[s]["status"] = "todo"; // tu peux forcer "todo" si nécessaire
        task[s]["createdAt"] = ctime(&timestamp);
        task[s]["updatedAt"] = ctime(&timestamp);
        saveJson();
        x = 0;

    } else if (cd == 2) { 
        if (task[id]) {
            task[id]["desc"] = desc;
            task[id]["updatedAt"] = ctime(&timestamp);
            saveJson();
        }

    } else if (cd == 3) { 
        if (task[id]) {
            task.removeMember(id);
            saveJson();
        }

    } else if (cd == 4) { 
        if (task[id]) {
            task[id]["status"] = status;
            task[id]["updatedAt"] = ctime(&timestamp);
            saveJson();
        }

    } else if (cd == 5) { 
        // Vérifier que dat est alloué et ln correct
        if (dat.ln <= 0 || !dat.creatdat) return "";

        for (Json::Value::ArrayIndex i = 0; i < task.size() && i < dat.ln; i++) {
            std::string key = std::to_string(i);
            if (task[key].isObject()) {
                dat.id[i]  = key;
                dat.creatdat[i]  = task[key]["createdAt"].asString();
                dat.desc[i]      = task[key]["desc"].asString();
                dat.status[i]    = task[key]["status"].asString();
                dat.updatedat[i] = task[key]["updatedAt"].asString();
            }
        }
        loaddat(0);

    } else if (cd == 6) { 
        // Filtrer par status
        int filteredCount = 0; // compteur pour les tâches filtrées
        for (Json::Value::ArrayIndex i = 0; i < task.size(); i++) {
            std::string key = std::to_string(i);
            if (task[key].isObject() && task[key]["status"].asString() == status) {
                dat.id[filteredCount]       = key;
                dat.creatdat[filteredCount] = task[key]["createdAt"].asString();
                dat.desc[filteredCount]     = task[key]["desc"].asString();
                dat.status[filteredCount]   = task[key]["status"].asString();
                dat.updatedat[filteredCount]= task[key]["updatedAt"].asString();
                filteredCount++;
            }
        }
        dat.ln = filteredCount; // mettre à jour la taille pour loaddat
        loaddat(0); // 0 = afficher toutes les tâches chargées dans dat
    }
    

    return "";
}
