/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Engine.h"
#include "Weapon.h"
#include <string>
#include <iostream>

class Transformer {
public:
    Transformer(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon);
    ~Transformer(); 
    
    bool move();
    bool transform();
    bool attack();
    
    void setName(std::string name);
    void setHealth(int health);
    void setPower(int power);
    void setTransformationTime(int transformationTime);
    void setEngine(Engine engine);
    void setWeapon(Weapon* weapon);
    
    std::string getName();
    int getHealth();
    int getPower();
    int getTransformationTime();
    Engine getEngine();
    Weapon* getWeapon();
    
private:
    std::string _name;
    int _health;
    int _power;
    int _transformationTime;
    Engine _engine;
    Weapon* _weapon;
};

#endif
