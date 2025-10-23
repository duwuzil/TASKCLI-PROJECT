#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <jsoncpp/json/json.h>
#include <string>


// Variables et fonctions globales
extern int x;
extern Json::Value task;

void loadJson();
void saveJson();
std::string jsParser(std::string id = "", std::string desc = "", std::string status = "", int cd = 0);

#endif
