/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "Transformer.h"
#include "Engine.h"
#include "Weapon.h"
#include <string>
#include <iostream>

Transformer::Transformer(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon)
    : _name(name), _health(health), _power(power), _transformationTime(transformationTime), _engine(engine), _weapon(weapon) {}
Transformer::~Transformer() { _weapon = nullptr; }
    
bool Transformer::move() { return true; }
bool Transformer::transform() { return true; }
bool Transformer::attack() { return true; }
    
void Transformer::setName(std::string name) { _name = name; }
void Transformer::setHealth(int health) { _health = health; }
void Transformer::setPower(int power) { _power = power; }
void Transformer::setTransformationTime(int transformationTime){ _transformationTime = transformationTime; }
void Transformer::setEngine(Engine engine){ _engine = engine; }
void Transformer::setWeapon(Weapon* weapon){ _weapon = weapon; }
    
std::string Transformer::getName(){ return _name; }
int Transformer::getHealth(){ return _health; }
int Transformer::getPower(){ return _power; }
int Transformer::getTransformationTime(){ return _transformationTime; }
Engine Transformer::getEngine(){ return _engine; }
Weapon* Transformer::getWeapon(){ return _weapon; }

