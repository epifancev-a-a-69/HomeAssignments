/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "Decepticon.h"
#include <string>

Decepticon::Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string specialAbility, bool isRuthless)
    : Transformer(name, health, power, transformationTime, engine, weapon), _specialAbility(specialAbility), _isRuthless(isRuthless) {}

bool Decepticon::sabotage() { return true; }

void Decepticon::setSpecialAbility(std::string specialAbility) { _specialAbility = specialAbility; }
void Decepticon::setIsRuthless(bool isRuthless) { _isRuthless = isRuthless; }

std::string Decepticon::getSpecialAbility() { return _specialAbility; }
bool Decepticon::getIsRuthless() { return _isRuthless; }

