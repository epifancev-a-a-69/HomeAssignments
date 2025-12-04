/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#ifndef DINOBOT_H
#define DINOBOT_H

#include "Autobot.h"
#include <string>

class Dinobot : public Autobot {
public:
    Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode, int ferocityLevel, bool isPackHunter);
    
    bool primalRage();
    
    void setFerocityLevel(int ferocityLevel);
    void setIsPackHunter(bool isPackHunter);
    
    int getFerocityLevel();
    bool getIsPackHunter();
    
private:
    int _ferocityLevel;
    bool _isPackHunter;
};

#endif
