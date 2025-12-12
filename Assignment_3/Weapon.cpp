/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string name, int damage): _name(name), _damage(damage) {}
Weapon::Weapon(): _name("null"), _damage(0) {}
    
void Weapon::setName(std::string name) { _name = name; }
void Weapon::setDamage(int damage) { _damage = damage; }
    
std::string Weapon::getName() { return _name; }
int Weapon::getDamage() { return _damage; }

