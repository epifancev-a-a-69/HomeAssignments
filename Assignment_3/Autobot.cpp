/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "Autobot.h"
#include <string>

Autobot::Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode)
    : Transformer(name, health, power, transformationTime, engine, weapon), _altMode(altMode), _hasHonorCode(hasHonorCode) {}
    
bool Autobot::protectCivilian() { return true; }
    
void Autobot::setAltMode(std::string altMode) { _altMode = altMode; }
void Autobot::setHonorCode(bool honorCode) { _hasHonorCode = honorCode; }
    
std::string Autobot::getAltMode() { return _altMode; }
bool Autobot::getHonorCode() { return _hasHonorCode; }

