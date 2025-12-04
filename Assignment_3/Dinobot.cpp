/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "Dinobot.h"
#include <string>

Dinobot::Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode, int ferocityLevel, bool isPackHunter)
    : Autobot(name, health, power, transformationTime, engine, weapon, altMode, hasHonorCode), _ferocityLevel(ferocityLevel), _isPackHunter(isPackHunter) {}

bool Dinobot::primalRage() { return true; }
    
void Dinobot::setFerocityLevel(int ferocityLevel) { _ferocityLevel = ferocityLevel; }
void Dinobot::setIsPackHunter(bool isPackHunter) { _isPackHunter = isPackHunter; }
    
int Dinobot::getFerocityLevel() { return _ferocityLevel; }
bool Dinobot::getIsPackHunter() { return _isPackHunter; }
