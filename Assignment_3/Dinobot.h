/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#ifndef DINOBOT_H
#define DINOBOT_H

#include "Autobot.h"
#include <string>

class Dinobot : public Autobot {
public:
    Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode, int ferocityLevel, bool isPackHunter);
    Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode);
    Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon);
    Dinobot(std::string name, int health, int power, int transformationTime, Engine engine);
    Dinobot(std::string name);
    Dinobot();

    bool primalRage();
    void vmethod1() override;
    void vmethod0() override;
    
    friend std::ostream& operator<<(std::ostream& os, const Dinobot& t);
    
    void setFerocityLevel(int ferocityLevel);
    void setIsPackHunter(bool isPackHunter);
    
    int getFerocityLevel();
    bool getIsPackHunter();
    
private:
    int _ferocityLevel;
    bool _isPackHunter;
};

#endif
