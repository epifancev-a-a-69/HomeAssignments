/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Transformer.h"
#include "Engine.h"
#include "Weapon.h"
#include <string>
#include <iostream>

Transformer::Transformer(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon)
    : _name(name), _health(health), _power(power), _transformationTime(transformationTime), _engine(engine), _weapon(weapon) {}
Transformer::Transformer(std::string name, int health, int power, int transformationTime, Engine engine)
    : _name(name), _health(health), _power(power), _transformationTime(transformationTime), _engine(engine), _weapon(nullptr) {}
Transformer::Transformer(std::string name)
    : _name(name), _health(0), _power(0), _transformationTime(0), _engine(), _weapon(nullptr) {}
Transformer::Transformer()
    : _name("null"), _health(0), _power(0), _transformationTime(0), _engine(), _weapon(nullptr) {}

Transformer::~Transformer()
{
    _weapon = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    os << "Transformer: " << t._name << ", Health: " << t._health
       << ", Power: " << t._power << ", Transformation time: " << t._transformationTime
       << ", Engine model: " << t._engine.getModel() << ", Engine Horsepower: " << t._engine.getHorsepower();

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

bool Transformer::move()
{
    return true;
}
bool Transformer::transform()
{
    return true;
}
bool Transformer::attack()
{
    return true;
}
void Transformer::vmethod1()
{
    std::cout << "Transformer. vmethod1" << std::endl;
}

void Transformer::setName(std::string name)
{
    _name = name;
}
void Transformer::setHealth(int health)
{
    _health = health;
}
void Transformer::setPower(int power)
{
    _power = power;
}
void Transformer::setTransformationTime(int transformationTime)
{
    _transformationTime = transformationTime;
}
void Transformer::setEngine(Engine engine)
{
    _engine = engine;
}
void Transformer::setWeapon(Weapon* weapon)
{
    _weapon = weapon;
}

std::string Transformer::getName()
{
    return _name;
}
int Transformer::getHealth()
{
    return _health;
}
int Transformer::getPower()
{
    return _power;
}
int Transformer::getTransformationTime()
{
    return _transformationTime;
}
Engine Transformer::getEngine()
{
    return _engine;
}
Weapon* Transformer::getWeapon()
{
    return _weapon;
}

