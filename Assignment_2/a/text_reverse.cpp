/*
Epifancev Artem
st142163@student.spbu.ru
assignment 2a
*/

#include "f.hpp"
#include <filesystem>
#include <fstream>
#include <algorithm>

void text_reverse(std::string name){

    std::ifstream inp; 
    inp.open(name,std::ios::binary|std::ios::in);
    
    int s = std::filesystem::file_size(name);
    char* arr = new char[s]; 
    inp.read(arr, s); 
    
    std::reverse(arr, arr + s);
    std::ofstream out("new_file.txt", std::ios::binary | std::ios::out); 
    out.write(arr, s); 

    delete[] arr;  
    inp.close();
    out.close();
    
    std::cout << "Данные успешно записаны в new_file\n";
}
