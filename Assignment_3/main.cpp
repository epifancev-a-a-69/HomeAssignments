/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include <iostream>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Engine.h"
#include "Weapon.h"

int main() {

    Engine Engine1("Quantum V12", 152);
    Engine Engine2("Quantum V12", 169);
    Engine Engine3("Quantum V12", 148);
    Weapon Cannon("Plasma Cannon", 69);
    Weapon Nixon("Laser Cannon", 52);
    Weapon Sony("Gorilla", 1488);

    Autobot optimus("Optimus Prime", 200, 80, 80, Engine1, &Cannon, "washing machine", true);
    Decepticon megatron("MEGAKNIGHT", 200, 100, 80, Engine2, &Nixon, "MMMMEGAKNIGHT", true);
    Dinobot titiRex("pivozavr", 199, 90, 60, Engine3, &Sony, "TREX", false, 13, true);

    if (optimus.protectCivilian()) {
        std::cout << "Health: " << optimus.getHealth() << std::endl;
    }
    if (megatron.sabotage()) {
        megatron.setSpecialAbility("psychosocial");
        std::cout << "New Special Ability: " << megatron.getSpecialAbility() << std::endl;
    }
    if (titiRex.primalRage()) {
        std::cout << titiRex.getEngine().getHorsepower() << std::endl;
    }

    return 0;
}
