/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
    Weapon(std::string name, int damage);
    
    void setName(std::string name);
    void setDamage(int damage);
    
    std::string getName();
    int getDamage();
    
private:
    std::string _name;
    int _damage;
};

#endif
