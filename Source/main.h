struct jsData {
    std::string* id;
    std::string* creatdat;
    std::string* desc;
    std::string* status;
    std::string* updatedat;
    int ln;
};

extern jsData dat; 

void loaddat(int tri);