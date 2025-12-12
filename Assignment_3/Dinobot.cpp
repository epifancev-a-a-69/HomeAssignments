/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Dinobot.h"
#include <string>

Dinobot::Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode, int ferocityLevel, bool isPackHunter)
    : Autobot(name, health, power, transformationTime, engine, weapon, altMode, hasHonorCode), _ferocityLevel(ferocityLevel), _isPackHunter(isPackHunter) {}
Dinobot::Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode)
    : Autobot(name, health, power, transformationTime, engine, weapon, altMode, hasHonorCode), _ferocityLevel(0), _isPackHunter(true) {}
Dinobot::Dinobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon)
    : Autobot(name, health, power, transformationTime, engine, weapon), _ferocityLevel(0), _isPackHunter(true) {}
Dinobot::Dinobot(std::string name, int health, int power, int transformationTime, Engine engine)
    : Autobot(name, health, power, transformationTime, engine), _ferocityLevel(0), _isPackHunter(true) {}
Dinobot::Dinobot(std::string name)
    : Autobot(name), _ferocityLevel(0), _isPackHunter(true) {}
Dinobot::Dinobot()
    : Autobot(), _ferocityLevel(0), _isPackHunter(true) {}

bool Dinobot::primalRage() { return true; }
void Dinobot::vmethod1() { std::cout << "Dinobot. vmethod1" << std::endl; }
void Dinobot::vmethod0() { std::cout << "Dinobot. vmethod0" << std::endl; }

std::ostream& operator<<(std::ostream& os, const Dinobot& t) {
    os << "Transformer: " << t._name << ", Health: " << t._health
       << ", Power: " << t._power << ", Transformation time: " << t._transformationTime
       << ", Engine model: " << t._engine.getModel() << ", Engine Horsepower: " << t._engine.getHorsepower()
       << ", Alt mode: " << t._altMode << ", Honor code: " << t._hasHonorCode
       << ", Ferocity: " << t._ferocityLevel << ", Pack hunter: " << t._isPackHunter;
      
    if (t._weapon!=nullptr) {
      os << ", Weapon: " << t._weapon->getName()
         << ", Weapon damage: " << t._weapon->getDamage();
    } else {
      os << ", Weapon: null";
    }
    return os;
}
void Dinobot::setFerocityLevel(int ferocityLevel) { _ferocityLevel = ferocityLevel; }
void Dinobot::setIsPackHunter(bool isPackHunter) { _isPackHunter = isPackHunter; }
    
int Dinobot::getFerocityLevel() { return _ferocityLevel; }
bool Dinobot::getIsPackHunter() { return _isPackHunter; }
