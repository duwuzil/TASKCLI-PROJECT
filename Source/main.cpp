#include <iostream>
#include "parser.h"
#include "jsonParser.h"
#include "main.h"



int main(int argc, char* argv[]) {
    loadJson(); // charger le JSON au démarrage
    dat.ln = task.size();
    dat.id = new std::string[dat.ln];
    dat.creatdat = new std::string[dat.ln];
    dat.desc = new std::string[dat.ln];
    dat.status = new std::string[dat.ln];
    dat.updatedat = new std::string[dat.ln];
    
    int ret = argparser(argc, argv);
    if(ret != 0) {
        std::cout << "Error: invalid command or missing parameters." << std::endl;
    } else {
        std::cout << "command valid. . ." << std::endl;
    }

    delete[] dat.id;
    delete[] dat.creatdat;
    delete[] dat.desc;
    delete[] dat.status;
    delete[] dat.updatedat;

    return 0;
}

void loaddat(int tri){
    if(tri == 0){
    for (int i = 0; i < dat.ln; i++) {
        std::cout << "liste" << std::endl << "ID : " << dat.id[i] << " | descritpion: " << dat.desc[i] << std::endl << "created AT : " << dat.creatdat[i] << std::endl << "updated at:" << dat.updatedat[i] << std::endl << "status : " << dat.status[i] << std::endl << std::endl;
    }
    } else if(tri == 1){
        for (int i = 0; i < dat.ln; i++) {
            if(dat.status[i] == "todo"){
                std::cout << "liste" << std::endl << "ID : " << dat.id[i] << " | descritpion: " << dat.desc[i] << std::endl << "created AT : " << dat.creatdat[i] << std::endl << "updated at:" << dat.updatedat[i] << std::endl << "status : " << dat.status[i] << std::endl << std::endl;
            }
        }
    } else if(tri == 2){
        for (int i = 0; i < dat.ln; i++) {
            if(dat.status[i] == "in-progress"){
                std::cout << "liste" << std::endl << "ID : " << dat.id[i] << " | descritpion: " << dat.desc[i] << std::endl << "created AT : " << dat.creatdat[i] << std::endl << "updated at:" << dat.updatedat[i] << std::endl << "status : " << dat.status[i] << std::endl << std::endl;
            }
        }
    } else if(tri == 3){
        for (int i = 0; i < dat.ln; i++) {
            if(dat.status[i] == "done"){
            std::cout << "liste" << std::endl << "ID : " << dat.id[i] << " | descritpion: " << dat.desc[i] << std::endl << "created AT : " << dat.creatdat[i] << std::endl << "updated at:" << dat.updatedat[i] << std::endl << "status : " << dat.status[i] << std::endl << std::endl;
            }
        }
    }
    
}