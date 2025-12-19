/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Decepticon.h"
#include <string>

Decepticon::Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string specialAbility, bool isRuthless)
    : Transformer(name, health, power, transformationTime, engine, weapon), _specialAbility(specialAbility), _isRuthless(isRuthless) {}
Decepticon::Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon)
    : Transformer(name, health, power, transformationTime, engine, weapon), _specialAbility("null"), _isRuthless(true) {}
Decepticon::Decepticon(std::string name, int health, int power, int transformationTime, Engine engine)
    : Transformer(name, health, power, transformationTime, engine), _specialAbility("null"), _isRuthless(true) {}
Decepticon::Decepticon(std::string name)
    : Transformer(name), _specialAbility("null"), _isRuthless(true) {}
Decepticon::Decepticon()
    : Transformer(), _specialAbility("null"), _isRuthless(true) {}

bool Decepticon::sabotage()
{
    return true;
}
void Decepticon::vmethod1()
{
    std::cout << "Decepticon. vmethod1" << std::endl;
}
void Decepticon::vmethod0()
{
    std::cout << "Decepticon. vmethod0" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Decepticon& t)
{
    os << "Transformer: " << t._name << ", Health: " << t._health
       << ", Power: " << t._power << ", Transformation time: " << t._transformationTime
       << ", Engine model: " << t._engine.getModel() << ", Engine Horsepower: " << t._engine.getHorsepower()
       << ", Special ability: " << t._specialAbility << ", Ruthless: " << t._isRuthless;

    if (t._weapon!=nullptr)
    {
        os << ", Weapon: " << t._weapon->getName()
           << ", Weapon damage: " << t._weapon->getDamage();
    }
    else
    {
        os << ", Weapon: null";
    }
    return os;
}
void Decepticon::setSpecialAbility(std::string specialAbility)
{
    _specialAbility = specialAbility;
}
void Decepticon::setIsRuthless(bool isRuthless)
{
    _isRuthless = isRuthless;
}

std::string Decepticon::getSpecialAbility()
{
    return _specialAbility;
}
bool Decepticon::getIsRuthless()
{
    return _isRuthless;
}

