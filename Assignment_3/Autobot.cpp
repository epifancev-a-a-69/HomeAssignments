/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Autobot.h"
#include <string>

Autobot::Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode)
    : Transformer(name, health, power, transformationTime, engine, weapon), _altMode(altMode), _hasHonorCode(hasHonorCode) {}
Autobot::Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon)
    : Transformer(name, health, power, transformationTime, engine, weapon), _altMode("null"), _hasHonorCode(true) {}
Autobot::Autobot(std::string name, int health, int power, int transformationTime, Engine engine)
    : Transformer(name, health, power, transformationTime, engine), _altMode("null"), _hasHonorCode(true) {}
Autobot::Autobot(std::string name)
    : Transformer(name), _altMode("null"), _hasHonorCode(true) {}
Autobot::Autobot()
    : Transformer(), _altMode("null"), _hasHonorCode(true) {}


bool Autobot::protectCivilian() { return true; }
void Autobot::vmethod1() { std::cout << "Autobot. vmethod1" << std::endl; }
void Autobot::vmethod0() { std::cout << "Autobot. vmethod0" << std::endl; }

std::ostream& operator<<(std::ostream& os, const Autobot& t) {
    os << "Transformer: " << t._name << ", Health: " << t._health
       << ", Power: " << t._power << ", Transformation time: " << t._transformationTime
       << ", Engine model: " << t._engine.getModel() << ", Engine Horsepower: " << t._engine.getHorsepower()
       << ", Alt mode: " << t._altMode << ", Honor code: " << t._hasHonorCode;
       
    if (t._weapon!=nullptr) {
      os << ", Weapon: " << t._weapon->getName()
         << ", Weapon damage: " << t._weapon->getDamage();
    } else {
      os << ", Weapon: null";
    }
    return os;
} 
void Autobot::setAltMode(std::string altMode) { _altMode = altMode; }
void Autobot::setHonorCode(bool honorCode) { _hasHonorCode = honorCode; }
    
std::string Autobot::getAltMode() { return _altMode; }
bool Autobot::getHonorCode() { return _hasHonorCode; }

