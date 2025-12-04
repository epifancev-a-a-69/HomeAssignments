/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include <string>

class Decepticon : public Transformer {
public:
    Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string specialAbility, bool isRuthless);
    
    bool sabotage();
    
    void setSpecialAbility(std::string specialAbility);
    void setIsRuthless(bool isRuthless);
    
    std::string getSpecialAbility();
    bool getIsRuthless();
    
private:
    std::string _specialAbility;
    bool _isRuthless;
};

#endif
