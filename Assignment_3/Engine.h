/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
public:
    Engine(std::string model, int horsepower);
    Engine();
    
    void setModel(std::string model);
    void setHorsepower(int horsepower);
    
    std::string getModel() const;
    int getHorsepower() const;
    
private:
    std::string _model;
    int _horsepower;
};

#endif
