/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include <string>

class Autobot : public Transformer {
public:
    Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode);
    
    bool protectCivilian();
    
    void setAltMode(std::string altMode);
    void setHonorCode(bool honorCode);
    
    std::string getAltMode();
    bool getHonorCode();
    
private:
    std::string _altMode;
    bool _hasHonorCode;
};

#endif
