/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include <string>

class Autobot : public Transformer
{
public:
    Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon, std::string altMode, bool hasHonorCode);
    Autobot(std::string name, int health, int power, int transformationTime, Engine engine, Weapon* weapon);
    Autobot(std::string name, int health, int power, int transformationTime, Engine engine);
    Autobot(std::string name);
    Autobot();

    bool protectCivilian();
    void vmethod1() override;
    void vmethod0() override;

    friend std::ostream& operator<<(std::ostream& os, const Autobot& t);

    void setAltMode(std::string altMode);
    void setHonorCode(bool honorCode);

    std::string getAltMode();
    bool getHonorCode();

protected:
    std::string _altMode;
    bool _hasHonorCode;
};

#endif
