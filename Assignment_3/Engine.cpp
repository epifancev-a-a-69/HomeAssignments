/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "Engine.h"
#include <string>

Engine::Engine(std::string model, int horsepower): _model(model), _horsepower(horsepower) {}
Engine::Engine(): _model("null"), _horsepower(0) {}
    
void Engine::setModel(std::string model) { _model = model; }
void Engine::setHorsepower(int horsepower) { _horsepower = horsepower; }
    
std::string Engine::getModel() const { return _model; }
int Engine::getHorsepower() const { return _horsepower; }

