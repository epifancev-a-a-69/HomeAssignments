/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include <string>

class Decepticon : public Transformer {
public:
    Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string specialAbility, bool isRuthless);
    Decepticon(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon);
    Decepticon(std::string name, int health, int power, int transformationTime, Engine engine);
    Decepticon(std::string name);
    Decepticon();

    bool sabotage();
    void vmethod1() override;
    void vmethod0() override;
    
    friend std::ostream& operator<<(std::ostream& os, const Decepticon& t);
    
    void setSpecialAbility(std::string specialAbility);
    void setIsRuthless(bool isRuthless);
    
    std::string getSpecialAbility();
    bool getIsRuthless();
    
private:
    std::string _specialAbility;
    bool _isRuthless;
};

#endif
